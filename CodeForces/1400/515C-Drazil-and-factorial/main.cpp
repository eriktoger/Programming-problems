
#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    int size;
    cin >> size;
    string str;
    cin >> str;

    string answer;
    for (auto c : str)
    {
        switch (c)
        {
        case '2':
        case '3':
        case '5':
        case '7':
            answer.push_back(c);
            break;
        case '4':
            answer.append("322");
            break;
        case '6':
            answer.append("53");
            break;
        case '8':
            answer.append("7222");
            break;
        case '9':
            answer.append("7332");
            break;
        default:
            break;
        }
    }

    sort(answer.begin(), answer.end(), greater<char>());
    cout << answer;
}
