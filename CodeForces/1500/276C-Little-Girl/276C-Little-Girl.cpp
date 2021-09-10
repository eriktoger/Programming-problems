#include "276C-Little-Girl.h"

void func(std::istream &is, std::ostream &os) {
    int arrayLength;
    int rounds;
    cin >> arrayLength;
    cin >> rounds;
    vector<int> numbers;
    numbers.reserve(arrayLength + 1);
    numbers.emplace_back(0);
    vector<unsigned long long> counts(arrayLength + 1, 0);
    vector<int> sum(arrayLength + 2, 0);

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
        //By adding upp everything (as we go) in sum we get the count for each index
        sum[start] += 1;
        sum[stop + 1] -= 1;
    }

    //And here we get how often each index is used
    unsigned long long tempS = 0;
    for (int i = 1; i < numbers.size(); i++) {
        tempS += sum[i];
        counts[i] = tempS;
    }

    sort(numbers.begin(), numbers.end());
    sort(counts.begin(), counts.end());
    unsigned long long answer = 0;
    for (int i = 1; i < numbers.size(); i++) {
        answer += counts[i] * numbers[i];
    }

    cout << answer;
}