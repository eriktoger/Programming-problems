#include <iostream>
using namespace std;

int main() {
    double limit = 3.0 / 7;
    double left = 0;
    int answer = 0;
    for (int i = 1; i < 428573; i++) {
        for (int j = i / limit; j <= 1000000; j++) {
            double quotient = static_cast<double>(i) / static_cast<double>(j);
            if (quotient < limit && quotient > left) {
                left = quotient;
                answer = i;
            }else if (quotient < limit) {
                break;
            }
        }
    }
    cout << "answer: " << answer << endl;

}
