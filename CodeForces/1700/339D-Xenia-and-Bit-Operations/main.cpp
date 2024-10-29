#include "main.h"

vector<int> getNumbers(std::istream &is, int nrOfNumbers)
{
    vector<int> numbers;
    numbers.reserve(nrOfNumbers);

    while (nrOfNumbers--)
    {
        int number;
        is >> number;
        numbers.emplace_back(number);
    }

    return numbers;
}

vector<vector<int>> initializeTree(const std::vector<int> &numbers, int exponent)
{
    vector<vector<int>> tree{numbers};
    while (exponent--)
    {
        vector<int> temp;
        tree.emplace_back(temp);
    }

    for (size_t i = 1; i < tree.size(); i++)
    {
        auto &level = tree[i - 1];
        auto &nextLevel = tree[i];
        for (size_t j = 0; j < level.size(); j += 2)
        {
            int first = level[j];
            int second = level[j + 1];
            int value = i % 2 == 1 ? first | second : first ^ second;
            nextLevel.emplace_back(value);
        }
    }

    return tree;
}

void updateTree(vector<vector<int>> &tree, int index, int newValue)
{
    tree[0][index] = newValue;

    for (size_t i = 1; i < tree.size(); i++)
    {
        int adjecentIndex = index % 2 == 0 ? index + 1 : index - 1;

        auto &level = tree[i - 1];
        int first = level[index];
        int second = level[adjecentIndex];
        int updatedValue = i % 2 == 1 ? first | second : first ^ second;

        int newIndex = index / 2;
        auto &nextLevel = tree[i];
        nextLevel[newIndex] = updatedValue;
        index = newIndex;
    }
}

void solution(std::istream &is, std::ostream &os)
{
    int exponent;
    is >> exponent;
    int testcases;
    is >> testcases;
    int nrOfnumbers = pow(2, exponent);
    auto numbers = getNumbers(is, nrOfnumbers);

    auto tree = initializeTree(numbers, exponent);

    while (testcases--)
    {
        size_t index;
        int newValue;
        is >> index;
        is >> newValue;
        index--;

        tree[0][index] = newValue;

        updateTree(tree, index, newValue);

        int answer = tree.back().back();
        os << answer << "\n";
    }
}
