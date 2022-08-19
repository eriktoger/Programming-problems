
#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    int size;
    int minutes;
    cin >> size;
    cin >> minutes;

    // get books
    vector<int> books(size);
    while (size--)
    {
        cin >> books[books.size() - size - 1];
    }

    unsigned first = 0;
    unsigned second = 0;
    int total = 0;

    unsigned answer = 0;
    while (second < books.size())
    {
        if (books[second] > minutes)
        {
            second++;
            first = second;
            continue;
        };

        if (total + books[second] <= minutes)
        {
            total += books[second];
            second++;
        }
        else
        {
            total -= books[first];
            first++;
        }

        if (first > second)
        {
            std::swap(first, second);
        }
        else
        {
            answer = max(answer, second - first);
        }
    }

    cout << answer;
}
