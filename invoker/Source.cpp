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
Базоый класс проверки решений
******************************************************************************/
class Invoker {
protected:
	// Информация о процессе
	PROCESS_INFORMATION processInformation;

	// Информация о запускаемом процессе
	STARTUPINFO startupInfo;

	// Имя исполняемого файла решения
	std::string applicationName;

	// Полный путь к рабочему каталогу для запуска решения
	std::string currentDirectory;

	// Имя входного файла
	std::string inputFilename;

	// Имя выходного файла
	std::string outputFilename;

	// Лимит памяти
	unsigned long memoryLimit;

	// Лимит времени
	unsigned long timeLimit;

	// Предельное время выполнения теста
	unsigned long executionTimeLimit;

	std::map<std::string, Subtask> subtasks;

	// Инициализация потоков
	virtual void prepareTest() = 0;

	// Проверка ответа
	Verdict checkTestResult();

	// Запуск одного теста
	Verdict runTest();

public:
	// Конструктор
	Invoker(std::string taskFilename, std::string submissionExecutable);

	// Запуск всех тестов
	void runAllTests();
};

// Конструктор
Invoker::Invoker(std::string taskFilename, std::string submissionExecutable) {
	
	// Открываем файл с описанием задачи
	std::ifstream taskFile(taskFilename);
	if (!taskFile.is_open()) {
		return;
	}

	// Читаем файл с описанием задачи
	nlohmann::json taskJson;
	taskFile >> taskJson;
	taskFile.close();

	// Имя исполняемого файла решения
	applicationName = submissionExecutable;
	
	// Рабочий каталог для проверки
	currentDirectory = "";

	// Лимит времени по умолчанию - 2 секунды
	timeLimit = jsonGet(taskJson, "timeout", 2000);

	// Лимит памяти по умолчанию - 256 мегабайта
	memoryLimit = jsonGet(taskJson, "memory", 256 * 1024 * 1024);

	// Имя входного файла по умолчанию - input.txt
	inputFilename = jsonGet(taskJson, "input_file", std::string("input.txt"));
	
	// Имя выходного файла по умолчанию - output.txt
	outputFilename = jsonGet(taskJson, "output_file", std::string("output.txt"));

	if (taskJson.find("test_suites") != taskJson.end()) {
		nlohmann::json testSuites = taskJson["test_suites"];
		for (nlohmann::json::iterator it = testSuites.begin(); it != testSuites.end(); ++it) {
			Subtask newSubtask;
			newSubtask.directory = it.key();
			newSubtask.name = jsonGet(it.value(), "name", newSubtask.directory);
			
			// Подсчет баллов по умолчанию - пропорциональный
			std::string partial = "partial";
			int res = jsonGet(it.value(), "scoring", partial);
			std::string scoring = jsonGet(it.value(), "scoring", partial);
			newSubtask.scoring = (scoring == partial) ? PARTIAL : ENTIRE;
			
			// Отображение результатов по умолчанию - полное
			std::string full = "full";
			std::string results = jsonGet(it.value(), "results", full);
			newSubtask.results = (results == full) ? FULL : BRIEF;

			subtasks[it.key()] = newSubtask;
		}
	}
}

// Запуск одного теста
Verdict Invoker::runTest() {

	// Текущий вердикт
	Verdict verdict;

	// Подготовка входных и выходных данных теста
	prepareTest();

	// Засекаем время
	SYSTEMTIME startTime;
	GetSystemTime(&startTime);

	// Пытаемся запустить процесс
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
		// Ждем завершения работы процесса
		DWORD result = WaitForSingleObject(processInformation.hProcess, executionTimeLimit);

		switch (result)
		{
		case WAIT_OBJECT_0: // Процесс завершился

							// Получим код возврата
			DWORD exitCode;
			BOOL result = GetExitCodeProcess(processInformation.hProcess, &exitCode);

			// Не удалось получить код возврата или код возврата содержит ошибку
			if ((!result) || (exitCode)) {
				verdict = RUNTIME_ERROR;
				break;
			}

			// Проверим время выполнения
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

			// Проверим данные об использовании памяти
			PROCESS_MEMORY_COUNTERS processMemoryCounters;
			GetProcessMemoryInfo(processInformation.hProcess, &processMemoryCounters, sizeof(processMemoryCounters));
			if (processMemoryCounters.PeakPagefileUsage > memoryLimit) {
				verdict = MEMORY_LIMIT;
				break;
			}

			// Проверяем ответ
			verdict = checkTestResult();
			break;

		case WAIT_TIMEOUT:

			// Время вышло
			verdict = TIME_LIMIT;

			// Снимаем процесс
			TerminateProcess(processInformation.hProcess, NO_ERROR);

			break;

		default:
			break;
		}
	}
	else {
		// Не удалось запустить процесс
		verdict = RUNTIME_ERROR;
	}

	return verdict;
}

Verdict Invoker::checkTestResult() {

}

// Запуск всех тестов
void Invoker::runAllTests() {
	// Обходим ассоциативный контейнер с подзадачами


}

/******************************************************************************
Класс для проверки решений в файловом режиме
******************************************************************************/
class FileInvoker : public Invoker {
	virtual void prepareTest();
};

void FileInvoker::prepareTest() {

	// Заполняем стартовую информацию нулями
	ZeroMemory(&startupInfo, sizeof(STARTUPINFO));

	// Копируем входной файл

	// Удаляем выходной файл
}

/******************************************************************************
Класс для проверки решений в консольном режиме
******************************************************************************/
class ConsoleInvoker : public Invoker {
	virtual void prepareTest();
};

void ConsoleInvoker::prepareTest() {

	// Заполняем стартовую информацию нулями
	ZeroMemory(&startupInfo, sizeof(STARTUPINFO));

	// Разрешаем дочернему процессу использовать входной и выходной файлы
	SECURITY_ATTRIBUTES securityAttributes;
	securityAttributes.nLength = sizeof(securityAttributes);
	securityAttributes.lpSecurityDescriptor = NULL;
	securityAttributes.bInheritHandle = TRUE;

	// Входной файл
	HANDLE input = CreateFile(
		inputFilename.c_str()                 // LPCSTR lpFileName
		, GENERIC_READ                        // DWORD dwDesiredAccess
		, FILE_SHARE_READ                     // dwSharedMode
		, &securityAttributes                 // LPSECURITY_ATTRIBUTES lpSecurityAttributes
		, OPEN_ALWAYS                         // DWORD dwCreationDisposition
		, FILE_ATTRIBUTE_NORMAL               // DWORD dwFladsAndAttributes
		, NULL                                // HANDLE hTemplateFile
	);

	// Выходной файл
	HANDLE output = CreateFile(
		outputFilename.c_str()                // LPCSTR lpFileName
		, GENERIC_WRITE                       // DWORD dwDesiredAccess
		, FILE_SHARE_WRITE                    // dwSharedMode
		, &securityAttributes                 // LPSECURITY_ATTRIBUTES lpSecurityAttributes
		, CREATE_ALWAYS                       // DWORD dwCreationDisposition
		, FILE_ATTRIBUTE_NORMAL               // DWORD dwFladsAndAttributes
		, NULL                                // HANDLE hTemplateFile
	);

	// Заполнем стартовую информацию
	startupInfo.cb = sizeof(STARTUPINFO);
	startupInfo.dwFlags |= STARTF_USESTDHANDLES;
	startupInfo.hStdInput = input;
	startupInfo.hStdError = NULL;
	startupInfo.hStdOutput = output;
}

/******************************************************************************
Точка входа
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
