
#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    int nrOfSubjects;

    cin >> nrOfSubjects;

    vector<Subject> subjects;
    while (nrOfSubjects--)
    {
        int date1;
        int date2;

        cin >> date1;
        cin >> date2;
        subjects.emplace_back(date1, date2);
    }
    sort(subjects.begin(), subjects.end());

    int earliestDate = -1;

    for (auto &subject : subjects)
    {
        if (earliestDate <= subject.date2)
        {
            earliestDate = subject.date2;
        }
        else
        {
            earliestDate = subject.date1;
        }
    }
    cout << earliestDate;
}
