#include "utils.h"
vector<int> getInstructions(vector<string> const &input)
{
    string instructionsString = input[4].substr(8);
    vector<string> instructionsVector = {instructionsString};
    auto instructionsList = splitOnDelimiter(instructionsVector, ",");
    vector<int> instructionNumbers;
    for (auto instruction : instructionsList[0])
    {
        instructionNumbers.push_back(stoi(instruction));
    }
    return instructionNumbers;
}

vector<int> solver(vector<string> const &input, const std::vector<int> &instructions, unsigned long long registerA, unsigned long long registerB, unsigned long long registerC)
{

    auto getComboValue = [&](int comboInstruction) -> long long
    {
        if (comboInstruction == 4)
        {
            return registerA;
        }
        else if (comboInstruction == 5)
        {
            return registerB;
        }
        else if (comboInstruction == 6)
        {
            return registerC;
        }

        return comboInstruction;
    };

    auto performDivision = [&](unsigned long long &targetRegister, int comboInstruction) -> void
    {
        auto tempA = registerA;
        auto denominator = getComboValue(comboInstruction);
        targetRegister = registerA >> denominator;
    };

    vector<int> outputs;

    int instructionPointer = 0;
    while (instructionPointer < instructions.size())
    {
        auto instruction = instructions[instructionPointer];
        auto comboInstruction = instructions[instructionPointer + 1];

        if (instruction == 0)
        {
            performDivision(registerA, comboInstruction);
        }
        else if (instruction == 1)
        {
            auto literalOperand = comboInstruction;
            registerB ^= literalOperand;
        }
        else if (instruction == 2)
        {
            auto comboValue = getComboValue(comboInstruction);
            registerB = comboValue % 8;
        }
        else if (instruction == 3)
        {
            if (registerA != 0)
            {
                instructionPointer = comboInstruction;
                continue;
            }
        }
        else if (instruction == 4)
        {
            registerB ^= registerC;
        }
        else if (instruction == 5)
        {
            auto comboValue = getComboValue(comboInstruction);
            auto output = comboValue % 8;
            outputs.emplace_back(output);
        }
        else if (instruction == 6)
        {
            performDivision(registerB, comboInstruction);
        }
        else if (instruction == 7)
        {
            performDivision(registerC, comboInstruction);
        }

        instructionPointer += 2;
    }
    return outputs;
}