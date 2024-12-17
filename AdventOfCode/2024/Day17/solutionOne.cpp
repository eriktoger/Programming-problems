#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{

    long long registerA = stoll(input[0].substr(11));
    long long registerB = stoll(input[1].substr(11));
    long long registerC = stoll(input[2].substr(11));
    auto instructions = getInstructions(input);

    auto outputs = solver(input, instructions, registerA, registerB, registerC);

    string result;
    for (int i = 0; i < outputs.size(); i++)
    {
        result += to_string(outputs[i]);
        if (i != outputs.size() - 1)
        {
            result += ",";
        }
    }

    return {result};
}
