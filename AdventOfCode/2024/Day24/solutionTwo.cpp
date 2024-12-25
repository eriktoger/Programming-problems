#include "solutionTwo.h"

regex valuePattern2(R"(^\s*(\w+):\s*(\S+)\s*$)");
regex connectionPattern2(R"(^(\w+)\s+(XOR|OR|AND)\s+(\w+)\s*->\s*(\w+)$)");

string binaryRepresentation(unsigned long long value)
{
    string binary = "";
    while (value > 0)
    {
        binary = to_string(value % 2) + binary;
        value /= 2;
    }
    return binary;
}

unsigned long long findDec(map<string, unsigned long long> values, string name)
{
    auto total = 0ull;
    for (const auto &value : values)
    {
        if (value.first.starts_with(name))
        {
            auto index = stoull(strip_z(value.first));
            total += (value.second << index);
        }
    }
    return total;
}

vector<string> solutionTwo(vector<string> const &input)
{
    map<string, unsigned long long> values;
    vector<string> connections;

    parseInput(input, values, connections);

    // 0 and 45 are special cases
    string prevCarryDestination = "gnn";
    for (int i = 1; i < 45; i++)
    {
        string paddingZero = i < 10 ? "0" : "";
        auto xName = "x" + paddingZero + to_string(i);
        auto yName = "y" + paddingZero + to_string(i);
        auto zName = "z" + paddingZero + to_string(i);

        auto xPlusYNoCarryInstructionV1 = xName + " XOR " + yName + " -> ";
        auto xPlusYNoCarryInstructionV2 = yName + " XOR " + xName + " -> ";
        // ghh
        string xPlusYNoCarry;
        auto xPlusYTheCarryInstructionV1 = xName + " AND " + yName + " -> ";
        auto xPlusYTheCarryInstructionV2 = yName + " AND " + xName + " -> ";

        // nck
        string xPlusYTheCarry;
        for (auto &line : connections)
        {
            if (line.starts_with(xPlusYNoCarryInstructionV1) || line.starts_with(xPlusYNoCarryInstructionV2))
            {
                xPlusYNoCarry = line.substr(line.length() - 3);
            }
            if (line.starts_with(xPlusYTheCarryInstructionV1) || line.starts_with(xPlusYTheCarryInstructionV2))
            {
                xPlusYTheCarry = line.substr(line.length() - 3);
            }
        }

        if (xPlusYNoCarry.empty() || xPlusYTheCarry.empty())
        {
            cout << to_string(i) + ": ErrorA: " << xPlusYNoCarry << " - " << xPlusYTheCarry << endl;
        }

        // z01 (check that this is the correct destination)
        auto resultV1Instruction = xPlusYNoCarry + " XOR " + prevCarryDestination;
        auto resultV2Instruction = prevCarryDestination + " XOR " + xPlusYNoCarry;

        auto carryV1Instruction = xPlusYNoCarry + " AND " + prevCarryDestination;
        auto carryV2Instruction = prevCarryDestination + " AND " + xPlusYNoCarry;
        // qhq
        string carry;
        bool zNameFound = false;
        for (auto &line : connections)
        {
            if (line.starts_with(resultV1Instruction) || line.starts_with(resultV2Instruction))
            {
                auto destination = line.substr(line.length() - 3);
                if (destination != zName)
                {
                    cout << i + ": ErrorB: " << destination << " != " << zName << endl;
                }
                else
                {
                    zNameFound = true;
                }
            }

            if (line.starts_with(carryV1Instruction) || line.starts_with(carryV2Instruction))
            {
                auto destination = line.substr(line.length() - 3);

                carry = destination;
            }
        }

        if (carry.empty())
        {
            cout << to_string(i) + ": ErrorC: " << carry << " - " << xPlusYTheCarry << endl;
        }
        if (!zNameFound)
        {
            cout << to_string(i) + ": ErrorD: " << zName << " not found" << endl;
        }

        string carryOldNewInstructionV1 = carry + " OR " + xPlusYTheCarry;
        string carryOldNewInstructionV2 = xPlusYTheCarry + " OR " + carry;

        bool carryFound = false;
        for (auto &line : connections)
        {

            if (line.starts_with(carryOldNewInstructionV1) || line.starts_with(carryOldNewInstructionV2))
            {
                auto destination = line.substr(line.length() - 3);

                prevCarryDestination = destination;
                carryFound = true;
            }
        }

        if (!carryFound)
        {
            cout << to_string(i) + ": ErrorE: " << carryOldNewInstructionV1 << " - " << carryOldNewInstructionV2 << endl;
        }
    }

    // I manually inspected the errors and changed the values in my input file.

    // changes
    //  bjm <-> z07
    //  hsw <-> z13
    //  z18 <-> skf
    //  wkr <-> nvr

    runAdder(connections, values);

    auto totalX = findDec(values, "x");
    auto totalY = findDec(values, "y");
    auto target = totalX + totalY;
    auto totalZ = findDec(values, "z");

    cout << "X: " << binaryRepresentation(totalX) << endl;
    cout << "Y: " << binaryRepresentation(totalY) << endl;
    cout << "T: " << binaryRepresentation(target) << endl;
    cout << "Z: " << binaryRepresentation(totalZ) << endl;

    return {};
}
