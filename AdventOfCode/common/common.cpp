#include "common.h"

vector<string> fromFileToVector(string fileName)
{

    ifstream myfile(fileName);

    vector<string> result;

    string line;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            result.emplace_back(line);
        }
        myfile.close();
    }
    else
    {
        throw std::runtime_error("Could not open file");
    }

    return result;
}

void fromVectorToFile(string fileName, vector<string> const &input)
{
    ofstream myfile(fileName);

    if (myfile.is_open())
    {
        for (auto const &line : input)
        {
            myfile << line << endl;
        }
        myfile.close();
    }
    else
    {
        throw std::runtime_error("Could not open file");
    }
}