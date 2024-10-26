#include "main.h"

const char mappedDigits[] = {'0', '1', '2', '3', '4', '4', '3', '2', '1', '0'};

void solution(std::istream &is, std::ostream &os)
{
    string digits;

    is >> digits;

    string answer = "";

    for (char digit : digits)
    {
        int index = 9 - (digit - '0');
        char mappedDigit = mappedDigits[index];
        bool nonLeadingZero = mappedDigit != '0' || answer.size() > 0;
        if (nonLeadingZero)
        {
            answer += mappedDigit;
        }
        else
        {
            answer += '9';
        }
    }

    os << answer;
}
