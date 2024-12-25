#include "utils.h"

void runAdder(vector<string> connections, map<string, unsigned long long> &values)
{

    while (!connections.empty())
    {
        vector<string> unHandledConnections;
        for (auto connection : connections)
        {
            smatch matches;
            if (regex_match(connection, matches, connectionPattern))
            {
                std::string firstValue = matches[1];
                std::string operation = matches[2];
                std::string secondValue = matches[3];
                std::string destination = matches[4];

                if (values.contains(firstValue) && values.contains(secondValue))
                {
                    if (operation == "AND")
                    {
                        values[destination] = values[firstValue] & values[secondValue];
                    }
                    else if (operation == "OR")
                    {
                        values[destination] = values[firstValue] | values[secondValue];
                    }
                    else if (operation == "XOR")
                    {
                        values[destination] = values[firstValue] ^ values[secondValue];
                    }
                }
                else
                {
                    unHandledConnections.emplace_back(connection);
                }
            }
        }

        if (unHandledConnections.size() == connections.size())
        {
            break;
        }

        connections = unHandledConnections;
    }
}

void parseInput(vector<string> const &input, map<string, unsigned long long> &values, vector<string> &connections)
{

    for (auto line : input)
    {
        smatch matches;
        if (regex_match(line, matches, valuePattern))
        {
            std::string key = matches[1];
            std::string value = matches[2];

            values[key] = stoi(value);
        }
        else if (line.contains("->"))
        {
            connections.emplace_back(line);
        }
    }
}

string strip_z(const string &input)
{
    return input.substr(1);
}