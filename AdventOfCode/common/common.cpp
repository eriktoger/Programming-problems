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

vector<vector<string>> splitLinesToWords(vector<string> const &input)
{
    vector<vector<string>> result;
    for (auto const &line : input)
    {
        vector<string> temp;
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            temp.emplace_back(word);
        }
        result.emplace_back(temp);
    }

    return result;
}