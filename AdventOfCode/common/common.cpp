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

auto toStoi = [](const string &str)
{ return stoi(str); };
vector<vector<int>> splitLinesToInt(vector<string> const &input)
{

    return splitLinesToNumbers<int>(input, toStoi);
}

auto toStoll = [](const string &str)
{ return stoll(str); };
vector<vector<long long>> splitLinesToLL(vector<string> const &input)
{
    return splitLinesToNumbers<long long>(input, toStoll);
}

bool isOutOfBounds(vector<string> const &input, int row, int col)
{
    if (row < 0 || col < 0)
    {
        return true;
    }
    auto castedRow = static_cast<size_t>(row);
    auto castedCol = static_cast<size_t>(col);

    return castedRow >= input.size() || castedCol >= input[0].size();
}
