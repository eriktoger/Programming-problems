#include "../Other/BigInteger/BigInteger.h"
#include <cmath>

using namespace std;

int main() {


    int answer = 0;
    BigInteger largestX = "0"s;

    for (int D = 2; D <= 1000; D++) {
        int sqr = sqrt(D);
        if (sqr * sqr == D) {
            continue;
        }
        BigInteger bigD = to_string(D);
        BigInteger limit = to_string(sqr);

        BigInteger m = "0"s;
        BigInteger d = "1"s;
        BigInteger a = limit.getNumber();

        BigInteger numm1 = "1"s;
        BigInteger num = a.getNumber();

        BigInteger denm1 = "0"s;
        BigInteger den = "1"s;

        while (true) {
            m = d * a - m;
            d = (bigD - m * m) / d;
            a = (limit + m) / d;

            BigInteger numm2 = numm1.getNumber();
            numm1 = num.getNumber();
            BigInteger denm2 = denm1.getNumber();
            denm1 = den.getNumber();

            num = a * numm1 + numm2;
            den = a * denm1 + denm2;

            BigInteger breaking = num * num - bigD * den * den;
            if (breaking.getNumber() == "1" && breaking.getIsPositive()) {
                break;
            }
        }

        if (largestX < num) {
            largestX = num.getNumber();
            answer = D;
        }

    }
    cout << largestX.getNumber() << endl;
    cout << answer << endl;
}