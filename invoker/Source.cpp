#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "windows.h"
#include "psapi.h"

#include "json.hpp"

enum Verdict {
	ACCEPTED,
	COMPILE_ERROR,
	MEMORY_LIMIT,
	PRESENTATION_ERROR,
	RUNTIME_ERROR,
	TIME_LIMIT,
	WRONG_ANSWER
};

enum Scoring {
	ENTIRE,
	PARTIAL
};

enum Results {
	BRIEF,
	FULL
};

typedef struct {
	std::string name;
	std::string directory;
	Scoring scoring;
	Results results;
	int score;
} Subtask;

template<typename T> jsonGet(nlohmann::json object, char * key, T defaultValue) {
	T answer;
	if (object.find(key) != object.end()) {
		answer = object[key];
	} 
	else {
		answer = defaultValue;
	}
	return answer;
}

/******************************************************************************
������ ����� �������� �������
******************************************************************************/
class Invoker {
protected:
	// ���������� � ��������
	PROCESS_INFORMATION processInformation;

	// ���������� � ����������� ��������
	STARTUPINFO startupInfo;

	// ��� ������������ ����� �������
	std::string applicationName;

	// ������ ���� � �������� �������� ��� ������� �������
	std::string currentDirectory;

	// ��� �������� �����
	std::string inputFilename;

	// ��� ��������� �����
	std::string outputFilename;

	// ����� ������
	unsigned long memoryLimit;

	// ����� �������
	unsigned long timeLimit;

	// ���������� ����� ���������� �����
	unsigned long executionTimeLimit;

	std::map<std::string, Subtask> subtasks;

	// ������������� �������
	virtual void prepareTest() = 0;

	// �������� ������
	Verdict checkTestResult();

	// ������ ������ �����
	Verdict runTest();

public:
	// �����������
	Invoker(std::string taskFilename, std::string submissionExecutable);

	// ������ ���� ������
	void runAllTests();
};

// �����������
Invoker::Invoker(std::string taskFilename, std::string submissionExecutable) {
	
	// ��������� ���� � ��������� ������
	std::ifstream taskFile(taskFilename);
	if (!taskFile.is_open()) {
		return;
	}

	// ������ ���� � ��������� ������
	nlohmann::json taskJson;
	taskFile >> taskJson;
	taskFile.close();

	// ��� ������������ ����� �������
	applicationName = submissionExecutable;
	
	// ������� ������� ��� ��������
	currentDirectory = "";

	// ����� ������� �� ��������� - 2 �������
	timeLimit = jsonGet(taskJson, "timeout", 2000);

	// ����� ������ �� ��������� - 256 ���������
	memoryLimit = jsonGet(taskJson, "memory", 256 * 1024 * 1024);

	// ��� �������� ����� �� ��������� - input.txt
	inputFilename = jsonGet(taskJson, "input_file", std::string("input.txt"));
	
	// ��� ��������� ����� �� ��������� - output.txt
	outputFilename = jsonGet(taskJson, "output_file", std::string("output.txt"));

	if (taskJson.find("test_suites") != taskJson.end()) {
		nlohmann::json testSuites = taskJson["test_suites"];
		for (nlohmann::json::iterator it = testSuites.begin(); it != testSuites.end(); ++it) {
			Subtask newSubtask;
			newSubtask.directory = it.key();
			newSubtask.name = jsonGet(it.value(), "name", newSubtask.directory);
			
			// ������� ������ �� ��������� - ����������������
			std::string partial = "partial";
			int res = jsonGet(it.value(), "scoring", partial);
			std::string scoring = jsonGet(it.value(), "scoring", partial);
			newSubtask.scoring = (scoring == partial) ? PARTIAL : ENTIRE;
			
			// ����������� ����������� �� ��������� - ������
			std::string full = "full";
			std::string results = jsonGet(it.value(), "results", full);
			newSubtask.results = (results == full) ? FULL : BRIEF;

			subtasks[it.key()] = newSubtask;
		}
	}
}

// ������ ������ �����
Verdict Invoker::runTest() {

	// ������� �������
	Verdict verdict;

	// ���������� ������� � �������� ������ �����
	prepareTest();

	// �������� �����
	SYSTEMTIME startTime;
	GetSystemTime(&startTime);

	// �������� ��������� �������
	BOOL result = CreateProcess(
		applicationName.c_str()     // LPCSTR lpApplicationName
		, NULL                      // LPSTR lpCommandLine
		, NULL                      // LPSECURITY_ATTRIBUTES lpProcessAttributes
		, NULL                      // LPSECURITY_ATTRIBUTES lpThreadAttributes
		, FALSE                     // BOOL bInheritHandles
		, NULL                      // DWORD dwCreationFlags
		, NULL                      // LPVOID lpEnvironment
		, currentDirectory.c_str()  // LPCSTR lpCurrentDirectory
		, &startupInfo              // LPSTARTUPINFO lpStartupInfo
		, &processInformation       // LPPROCESS_INFORMATION lpProcessInformation
	);

	if (result) {
		// ���� ���������� ������ ��������
		DWORD result = WaitForSingleObject(processInformation.hProcess, executionTimeLimit);

		switch (result)
		{
		case WAIT_OBJECT_0: // ������� ����������

							// ������� ��� ��������
			DWORD exitCode;
			BOOL result = GetExitCodeProcess(processInformation.hProcess, &exitCode);

			// �� ������� �������� ��� �������� ��� ��� �������� �������� ������
			if ((!result) || (exitCode)) {
				verdict = RUNTIME_ERROR;
				break;
			}

			// �������� ����� ����������
			SYSTEMTIME stopTime;
			GetSystemTime(&stopTime);
			int time = (stopTime.wHour - startTime.wHour) * 60 * 60 * 1000
				+ (stopTime.wMinute - startTime.wMinute) * 60 * 1000
				+ (stopTime.wSecond - startTime.wSecond)
				+ (stopTime.wMilliseconds - startTime.wMilliseconds);
			if (time > timeLimit) {
				verdict = TIME_LIMIT;
				break;
			}

			// �������� ������ �� ������������� ������
			PROCESS_MEMORY_COUNTERS processMemoryCounters;
			GetProcessMemoryInfo(processInformation.hProcess, &processMemoryCounters, sizeof(processMemoryCounters));
			if (processMemoryCounters.PeakPagefileUsage > memoryLimit) {
				verdict = MEMORY_LIMIT;
				break;
			}

			// ��������� �����
			verdict = checkTestResult();
			break;

		case WAIT_TIMEOUT:

			// ����� �����
			verdict = TIME_LIMIT;

			// ������� �������
			TerminateProcess(processInformation.hProcess, NO_ERROR);

			break;

		default:
			break;
		}
	}
	else {
		// �� ������� ��������� �������
		verdict = RUNTIME_ERROR;
	}

	return verdict;
}

Verdict Invoker::checkTestResult() {

}

// ������ ���� ������
void Invoker::runAllTests() {
	// ������� ������������� ��������� � �����������


}

/******************************************************************************
����� ��� �������� ������� � �������� ������
******************************************************************************/
class FileInvoker : public Invoker {
	virtual void prepareTest();
};

void FileInvoker::prepareTest() {

	// ��������� ��������� ���������� ������
	ZeroMemory(&startupInfo, sizeof(STARTUPINFO));

	// �������� ������� ����

	// ������� �������� ����
}

/******************************************************************************
����� ��� �������� ������� � ���������� ������
******************************************************************************/
class ConsoleInvoker : public Invoker {
	virtual void prepareTest();
};

void ConsoleInvoker::prepareTest() {

	// ��������� ��������� ���������� ������
	ZeroMemory(&startupInfo, sizeof(STARTUPINFO));

	// ��������� ��������� �������� ������������ ������� � �������� �����
	SECURITY_ATTRIBUTES securityAttributes;
	securityAttributes.nLength = sizeof(securityAttributes);
	securityAttributes.lpSecurityDescriptor = NULL;
	securityAttributes.bInheritHandle = TRUE;

	// ������� ����
	HANDLE input = CreateFile(
		inputFilename.c_str()                 // LPCSTR lpFileName
		, GENERIC_READ                        // DWORD dwDesiredAccess
		, FILE_SHARE_READ                     // dwSharedMode
		, &securityAttributes                 // LPSECURITY_ATTRIBUTES lpSecurityAttributes
		, OPEN_ALWAYS                         // DWORD dwCreationDisposition
		, FILE_ATTRIBUTE_NORMAL               // DWORD dwFladsAndAttributes
		, NULL                                // HANDLE hTemplateFile
	);

	// �������� ����
	HANDLE output = CreateFile(
		outputFilename.c_str()                // LPCSTR lpFileName
		, GENERIC_WRITE                       // DWORD dwDesiredAccess
		, FILE_SHARE_WRITE                    // dwSharedMode
		, &securityAttributes                 // LPSECURITY_ATTRIBUTES lpSecurityAttributes
		, CREATE_ALWAYS                       // DWORD dwCreationDisposition
		, FILE_ATTRIBUTE_NORMAL               // DWORD dwFladsAndAttributes
		, NULL                                // HANDLE hTemplateFile
	);

	// �������� ��������� ����������
	startupInfo.cb = sizeof(STARTUPINFO);
	startupInfo.dwFlags |= STARTF_USESTDHANDLES;
	startupInfo.hStdInput = input;
	startupInfo.hStdError = NULL;
	startupInfo.hStdOutput = output;
}

/******************************************************************************
����� �����
******************************************************************************/
int main(int argc, char **argv) {
	//char a[1000000];
	//for (int i = 0; i < 1000000; i++) {
	//	a[i] = i % 256;
	//}
	//for (int i = 0; i < 1000000; i++) {
	//	std::cout << "Hello World! " << a[i] << std::endl;
	//}
	//HANDLE handle = GetCurrentProcess();
	//PROCESS_MEMORY_COUNTERS pmc;
	//GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
	//std::cout << pmc.PeakPagefileUsage << std::endl;
	return 0;
}
