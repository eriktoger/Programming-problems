#include <iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;

unsigned long long int lookUp(int smallest, int idx, unsigned long long int *dynamic, map<int, unsigned long long int> &totalValues);

void boredom() {

    int n;
    cin >> n;
    unsigned long long int dynamic[100000] = {0};
    int largest = 0;
    int smallest = 100000;
    vector<int> numbers;

    while (n--) {
        int a;
        cin >> a;
        numbers.emplace_back(a);
        largest = max(largest, a);
        smallest = min(smallest, a);
    }


    map<int, unsigned long long int> totalValues;
    sort(numbers.begin(), numbers.end());
    unsigned long long int currentNumber = numbers[0];
    unsigned long long int amount = 0;
    for (int i : numbers) {
        if (i == currentNumber) {
            amount++;
        } else {
            totalValues[currentNumber] = amount * currentNumber;
            currentNumber = i;
            amount = 1;
        }
    }


    totalValues[currentNumber] = amount * currentNumber;
    unsigned long long int answer = lookUp(smallest, largest, dynamic, totalValues);
    cout << answer;


}


unsigned long long int lookUp(int smallest, int idx, unsigned long long int *dynamic, map<int, unsigned long long int> &totalValues) {

    unsigned long long int lookUp1, lookUp2;

    if (idx == 0 || idx < smallest) {
        return 0;
    }
    if (idx == 1) {
        if (totalValues.find(idx) != totalValues.end()) {
            return totalValues[idx];
        } else {
            return 0;
        }
    }

    if (dynamic[idx - 1] == 0) {
        lookUp1 = lookUp(smallest, idx - 1, dynamic, totalValues);
        dynamic[idx - 1] = lookUp1;
    } else {
        lookUp1 = dynamic[idx - 1];
    }

    if (dynamic[idx - 2] == 0) {
        lookUp2 = lookUp(smallest, idx - 2, dynamic, totalValues);
        dynamic[idx - 2] = lookUp2;
    } else {
        lookUp2 = dynamic[idx - 2];
    }

    unsigned long long int fromTotalValues;
    if (totalValues.find(idx) != totalValues.end()) {
        fromTotalValues = totalValues[idx];
    } else {
        fromTotalValues = 0;
    }
    unsigned long long int sum = lookUp2 + fromTotalValues;
    return max(lookUp1, sum);
}