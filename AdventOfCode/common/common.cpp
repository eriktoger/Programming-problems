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

vector<vector<string>> splitOnDelimiter(const vector<string> &input, const string &delimiter)
{
    vector<vector<string>> result;
    for (const auto &line : input)
    {
        vector<string> temp;
        size_t start = 0;
        size_t end = 0;

        while ((end = line.find(delimiter, start)) != string::npos)
        {
            temp.emplace_back(line.substr(start, end - start));
            start = end + delimiter.length();
        }

        temp.emplace_back(line.substr(start));
        result.emplace_back(temp);
    }

    return result;
}

vector<vector<int>> splitLinesToInts(vector<string> const &input)
{
    vector<vector<int>> result;
    for (auto const &line : input)
    {
        vector<int> temp;
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            temp.emplace_back(stoi(word));
        }
        result.emplace_back(temp);
    }

    return result;
}