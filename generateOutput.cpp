#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

#include "myPath.h"

using namespace std;

void printMain(ofstream &outfile)
{
    outfile << "\n";
    outfile << "int main() {\n";
    outfile << "   ios_base::sync_with_stdio(false);\n";
    outfile << "   cin.tie(NULL);\n";
    outfile << "   solution();\n";
    outfile << "   return 0;\n";
    outfile << "}\n";
}

void readHeaderFile(ofstream &outfile, string path)
{
    string headerFilename = "main.h";
    ifstream headerfile;
    headerfile.open(path + headerFilename);

    if (headerfile.is_open())
    {
        std::string line;

        while (std::getline(headerfile, line))
        {
            if (line.find("COMPETITIVE_PROGRAMMING_MAIN_H") == string::npos)
            {
                outfile << line << "\n";
            }
        }
    }
}

void readCppFile(ofstream &outfile, string path)
{
    string cppFilename = "main.cpp";
    ifstream cppfile;
    cppfile.open(path + cppFilename);

    if (cppfile.is_open())
    {
        std::string line;
        while (std::getline(cppfile, line))
        {
            if (line.find("#include \"main.h\"") == string::npos)
            {
                outfile << line << "\n";
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Enter the path as argument\n";
        return 1;
    }
    myPath.append(argv[1]);

    ofstream outfile;

    outfile.open(myPath + "output.cpp");

    readHeaderFile(outfile, myPath);

    readCppFile(outfile, myPath);

    printMain(outfile);
    return 0;
}
