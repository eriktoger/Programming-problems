#include "solutionOne.h"

long long findSum(vector<long long> const &results, long long sum, size_t index)
{
    long long target = results[0];
    if (sum > target)
    {
        return -1;
    }

    if (index >= results.size())
    {
        return sum == target ? target : -1;
    }

    long long addition = findSum(results, sum + results[index], index + 1);
    long long multiplication = findSum(results, sum * results[index], index + 1);

    return addition == -1 ? multiplication : addition;
}

vector<string> solutionOne(vector<string> const &input)
{
    auto numbers = splitLinesToLL(input);

    long long totalSum = 0;
    for (auto const &number : numbers)
    {
        auto sum = findSum(number, number[1], 2);
        if (sum == number[0])
        {
            totalSum += sum;
        }
    }

    return {to_string(totalSum)};
}
