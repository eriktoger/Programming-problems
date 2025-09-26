#include "main.h"

void solution(std::istream &is, std::ostream &os)
{
    string word;
    is >> word;

    string target = "hello";
    int targetIndex = 0;

    for (char c : word)
    {
        if (c == target[targetIndex])
        {
            targetIndex++;
        }
        if (targetIndex == target.length())
        {

            break;
        }
    }

    if (targetIndex == target.length())
    {
        os << "YES" << endl;
    }
    else
    {
        os << "NO" << endl;
    }
}
