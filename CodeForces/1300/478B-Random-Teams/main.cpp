#include "main.h"

long long sum(long long s)
{
    return s * (s - 1) / 2;
}

void func(std::istream &is, std::ostream &os)
{
    long long n;
    long long m;

    is >> n;
    is >> m;
    long long maxTeamMembers = n + 1 - m;
    long long maxAnswer = sum(maxTeamMembers);

    long long minTeamMembers = n / m + (n % m != 0);
    long long fullGroups = m * minTeamMembers;
    long long groupsWithOneLess = fullGroups - n;
    long long groupsWithOneMore = m - groupsWithOneLess;
    long long minAnswer = groupsWithOneLess * sum((n / m)) + groupsWithOneMore * sum(minTeamMembers);

    os << minAnswer << " " << maxAnswer;
}
