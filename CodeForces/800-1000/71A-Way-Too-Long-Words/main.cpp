#include "main.h"

void solution(std::istream &is, std::ostream &os)
{
    int testcases;

    is >> testcases;

    while(testcases--) {
        string word;
        is >> word;
        if(word.length() > 10) {
            os << word[0] << word.length() - 2 << word[word.length() - 1] << "\n";
        } else {
            os << word << "\n";
        }
    }

    
}
