#include "createOutput.h"
#include "myPath.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <dirent.h>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        cout << "Enter the path as argument\n";
    }

    struct dirent *pDirent;
    DIR *pDir;
    string pathString = myPath;
    pathString.append(argv[1]);
    const char *path = pathString.c_str();
    pDir = opendir(path);
    if (pDir == NULL)
    {
        printf("Cannot open directory '%s'\n", path);
        return 1;
    }

    // Process each entry.
    Data data;
    vector<string> fileNames;
    while ((pDirent = readdir(pDir)) != NULL)
    {
        string fileName = pDirent->d_name;
        if (fileName == "main")
        {
            continue;
        }
        auto dotIdx = fileName.find('.');

        string suffix = fileName.substr(dotIdx);
        string name = fileName.substr(0, dotIdx);
        if (suffix == ".cpp" || suffix == ".h")
        {
            if (name != "output" && (fileName.find("TEST") > fileName.size()))
            {
                readFile(path, fileName, data);
            }
            fileNames.emplace_back(fileName);
        }
    }

    // Close directory and exit.
    closedir(pDir);

    ofstream outfile;
    string pathStr = path;
    outfile.open(pathStr + "output.cpp");

    removeIncludesWithFileNames(fileNames, data.includes);
    writeToFile(data.includes, outfile);
    writeToFile(data.classes, outfile);
    writeToFile(data.functionDeclerations, outfile);
    string funcName = findFuncName(data.functionDeclerations);
    printMain(funcName, outfile);
    writeToFile(data.functions, outfile);

    outfile.close();

    return 0;
}

void readFile(const char *path, string fileName, Data &data)
{
    ifstream infile;
    infile.open(path + fileName);
    if (infile.is_open())
    {
        std::string line;
        int leftBraces = 0;
        int rightBraces = 0;
        string function;
        string statement;
        while (std::getline(infile, line))
        {
            statement += line;
            if (line != "\n")
            {
                statement += '\n';
            }

            if (line.back() == ';' || line.back() == '{' || line.back() == '}' || line[0] == '#' ||
                line.substr(0, 5) == "using")
            {

                if (line[0] == '#' || line.substr(0, 5) == "using")
                {
                    if (statement.find("COMPETITIVE_PROGRAMMING") > statement.size())
                    {
                        data.includes.emplace_back(statement);
                    }
                }
                else
                {
                    function += statement;
                    // function += '\n';
                    for (char const &c : statement)
                    {
                        if (c == '{')
                        {
                            leftBraces++;
                        }
                        if (c == '}')
                        {
                            rightBraces++;
                        }
                    }
                    if (leftBraces > 0 && leftBraces == rightBraces)
                    {
                        if (function.substr(1, 5) == "class" || function.substr(1, 6) == "struct")
                        {
                            data.classes.emplace_back(function);
                        }
                        else
                        {
                            data.functions.emplace_back(function);
                        }
                        function = "";
                        leftBraces = 0;
                        rightBraces = 0;
                    }
                    else if (leftBraces == rightBraces && !statement.empty())
                    {
                        data.functionDeclerations.emplace_back(statement);
                    }
                }
                statement = "";
            }
        }
    }

    infile.close();
}

void writeToFile(vector<string> &text, ofstream &outfile)
{
    for (auto const &item : text)
    {
        outfile << item;
    }
}

string findFuncName(vector<string> const &functionsDeclarations)
{

    for (auto const &name : functionsDeclarations)
    {
        if (name.find("std::istream &is = cin, std::ostream &os = cout") < name.size())
        {
            int space = name.find(' ');
            int parenthesis = name.find('(');
            return name.substr(space, parenthesis - space);
        }
    }

    return "notFound";
}

void printMain(string &funcName, ofstream &outfile)
{
    outfile << "int main() {\n";
    outfile << "   ios_base::sync_with_stdio(false);\n";
    outfile << "   cin.tie(NULL);\n";
    outfile << "  " << funcName << "();\n";
    outfile << "   return 0;\n";
    outfile << "}\n";
}

void removeIncludesWithFileNames(vector<string> const &fileNames, vector<string> &includes)
{
    includes.erase(std::remove_if(includes.begin(),
                                  includes.end(),
                                  [&fileNames](const string &name)
                                  {
                                      for (auto const &filename : fileNames)
                                      {
                                          if (name.find(filename) < name.size())
                                          {
                                              return true;
                                          }
                                      }
                                      return false;
                                  }),
                   includes.end());
}
