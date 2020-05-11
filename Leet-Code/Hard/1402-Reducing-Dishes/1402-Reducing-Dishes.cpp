#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSatisfaction(vector<int> &satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    int sum = 0;
    if (satisfaction.back() <= 0) {
        return 0;
    }
    if (satisfaction.front() < 0) {
        int idx = 0;
        while (idx < satisfaction.size()) {
            int tempSum = 0;
            for (int i = idx; i < satisfaction.size(); i++) {
                tempSum += satisfaction[i] * (i - idx + 1);
            }
            if (tempSum > sum) {
                sum = tempSum;
            }
            if (satisfaction[idx] >= 0){
                break;
            }
            idx++;
        }
        return sum;
    }

    for (int i = 0; i < satisfaction.size(); i++) {
        sum += satisfaction[i] * (i+ 1);
    }
    return sum;

}
