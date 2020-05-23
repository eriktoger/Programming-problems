

#include <string>
#include <vector>
using namespace  std;
#ifndef COMPETETIVE_PROGRAMMING_CREATEOUTPUT_H
#define COMPETETIVE_PROGRAMMING_CREATEOUTPUT_H

struct Data{
    vector <string> includes;
    vector <string> functionDeclerations;
    vector <string> functions;
    vector <string> mainFunc;
    vector <string> classes;
};

void readFile(const char *path,string fileName, Data &data);
void writeToFile(vector<string> &text,ofstream &outfile);
string findFuncName( vector <string> const &functionsDeclarations);
void removeIncludesWithFileNames(vector <string> const &fileNames, vector<string> &includes);
void printMain(string &funcName, ofstream &outfile);

#endif //COMPETETIVE_PROGRAMMING_CREATEOUTPUT_H
