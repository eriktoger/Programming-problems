#include "solutionTwo.h"

unsigned long long calcRegisterA(const vector<unsigned long long> &numbers)
{
    unsigned long long registerA = 0;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        registerA += numbers[i] << (3 * i);
    }
    return registerA;
}

void updateNumbers(const vector<int> &instructions, std::vector<int> outputs, vector<unsigned long long> &numbers, int &currentIndex)
{
    if (instructions.size() == outputs.size() && instructions[currentIndex] == outputs[currentIndex])
    {
        currentIndex--;
    }
    else
    {
        numbers[currentIndex]++;
        while (numbers[currentIndex] == 8)
        {
            numbers[currentIndex] = 0;
            currentIndex++;
            numbers[currentIndex]++;
        }
    }
}

vector<string> solutionTwo(vector<string> const &input)
{

    auto instructions = getInstructions(input);
    vector numbers(instructions.size(), 0ull);
    int currentIndex = instructions.size() - 1;
    unsigned long long trueRegisterA = 0;
    unsigned long long registerB = stoll(input[1].substr(11));
    unsigned long long registerC = stoll(input[2].substr(11));

    while (currentIndex >= 0)
    {
        auto registerA = calcRegisterA(numbers);
        trueRegisterA = registerA;

        auto outputs = solver(input, instructions, registerA, registerB, registerC);

        updateNumbers(instructions, outputs, numbers, currentIndex);
    }

    return {to_string(trueRegisterA)};
}
