#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{
    map<string, unsigned long long> values;
    vector<string> connections;

    parseInput(input, values, connections);

    runAdder(connections, values);

    unsigned long long total = 0;
    for (const auto &value : values)
    {
        if (value.first.starts_with("z"))
        {
            auto index = stoull(strip_z(value.first));
            total += (value.second << index);
        }
    }

    return {to_string(total)};
}
