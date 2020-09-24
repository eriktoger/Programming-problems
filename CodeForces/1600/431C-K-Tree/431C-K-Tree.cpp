
#include "431C-K-Tree.h"



void add(int &a, int b) {
    a += b;
    a %=  (int) 1e9 + 7;
}

void kTree(std::istream &is, std::ostream &os) {

    int dp[100][2];

    dp[0][0] = 1;
    dp[0][1] = 0;
    int totalWeight, edges, minValue;
    cin >> totalWeight;
    cin >> edges;
    cin >> minValue;

    for (int i = 1; i <= totalWeight; i++) {
        dp[i][0] = dp[i][1] = 0;

        for (int j = 1; j <= min(i,edges); j++) {

            if (j < minValue) {
                add(dp[i][0], dp[i - j][0]);
            } else {
                add(dp[i][1], dp[i - j][0]);
            }
            add(dp[i][1], dp[i - j][1]);
        }
    }
    cout << dp[totalWeight][1];
}


