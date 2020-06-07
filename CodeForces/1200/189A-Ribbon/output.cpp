
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void ribbon(std::istream &is = cin, std::ostream &os = cout);
void cutting(int n,int const num[3],map<int,int> &pieces);
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ribbon();
   return 0;
}


void ribbon(std::istream &is, std::ostream &os) {

    int n, a, b, c;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    int num[3]{a, b, c};
    sort(num, num + 3);

    map<int, int> pieces;
    pieces[n] = 0;

    cutting(n, num, pieces);

    cout << pieces[0];

}

void cutting(int n, int const num[3], map<int, int> &pieces) {

    for (int i = 0; i < 3; i++) {
        int m = n - num[i];
        if (m >= 0) {
            if (pieces.find(m) == pieces.end()) {
                pieces[m] = pieces[n] + 1;
                cutting(m,num,pieces);
            } else {
                pieces[m] = max(pieces[m],pieces[n] + 1);
            }
        }
    }
}
