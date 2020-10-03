#include "276C-Little-Girl.h"

void func(std::istream &is, std::ostream &os) {
    int arrayLength;
    int rounds;
    cin >> arrayLength;
    cin >> rounds;
    vector<int> numbers;
    numbers.reserve(arrayLength + 1);
    numbers.emplace_back(0);
    vector<int> counts(arrayLength + 1, 0);

    int temp;
    while (arrayLength--) {
        cin >> temp;
        numbers.emplace_back(temp);
    }
    int start;
    int stop;
    while (rounds--) {
        cin >> start;
        cin >> stop;
        for (int i = start; i <= stop; i++) {
            counts[i]++;
        }
    }
    sort(numbers.begin(), numbers.end());
    sort(counts.begin(), counts.end());
    unsigned long long answer = 0;
    for (int i = 1; i < numbers.size(); i++) {
        answer += counts[i] * numbers[i];
    }

    cout << answer;
}