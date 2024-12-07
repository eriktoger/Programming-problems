#include "solutionTwo.h"

long long findSum2(vector<long long> const &results, long long sum, size_t index)
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

    long long addition = findSum2(results, sum + results[index], index + 1);
    long long multiplication = findSum2(results, sum * results[index], index + 1);
    long long concatedSum = stoll(to_string(sum) + to_string(results[index]));
    long long concat = findSum2(results, concatedSum, index + 1);

    return (addition != -1) ? addition : (multiplication != -1 ? multiplication : concat);
}

vector<string> solutionTwo(vector<string> const &input)
{
    auto numbers = splitLinesToLL(input);

    long long totalSum = 0;
    for (auto const &number : numbers)
    {
        auto sum = findSum2(number, number[1], 2);
        if (sum == number[0])
        {
            totalSum += sum;
        }
    }

    return {to_string(totalSum)};
}
