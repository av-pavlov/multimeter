#include "testlib.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char * argv[])
{
    setName("compare files as sequence of lines");
    registerTestlibCmd(argc, argv);

    std::string strAnswer;

    std::string j = ans.readString();

    strAnswer = j;
    std::string p = ouf.readString();

    std::size_t space = j.find(" ");

    if (space!=std::string::npos) {
        double x = atof(j.substr(0,space).c_str()),
               y = atof(j.c_str()+space+1);
        space = p.find(" ");
        if (space==std::string::npos) 
            quitf(_wa, "wrong answer: - expected: '%s', found: '%s'", compress(j).c_str(), compress(p).c_str());
        double x_ = atof(p.substr(0,space).c_str()),
               y_ = atof(p.c_str()+space+1);
        if (x-x_>1E-3 || y - y_>1E-3)
            quitf(_wa, "wrong answer: - expected: '%s', found: '%s'", compress(j).c_str(), compress(p).c_str());    
    }
    else 
        if (j != p)
            quitf(_wa, "lines differ - expected: '%s', found: '%s'", compress(j).c_str(), compress(p).c_str());
    
    quitf(_ok, compress(strAnswer).c_str());
}
