#include "../Other/BigInteger/BigInteger.h"
#include <cmath>
using namespace std;
int main(){


    int result = 0;
    BigInteger pmax = BigInteger("0");

    for(int D =2; D <= 1000; D++){
        int sqr = sqrt(D);
        if( sqr*sqr == D){
            continue;
        }
        BigInteger bigD = BigInteger(to_string(D));
        BigInteger limit = BigInteger(to_string(sqr));

        BigInteger m = BigInteger("0");
        BigInteger d = BigInteger("1");
        BigInteger a = BigInteger(limit.getNumber());

        BigInteger numm1 = BigInteger("1");;
        BigInteger num = BigInteger(a.getNumber());

        BigInteger denm1 = BigInteger("0");
        BigInteger den = BigInteger("1");

        while( true ){
            m = (d * a) - m;
            d = (bigD - (m * m) ) / d;
            a = (limit + m) / d;

            BigInteger numm2 = BigInteger(numm1.getNumber());
            numm1 = BigInteger(num.getNumber());
            BigInteger denm2 = BigInteger(denm1.getNumber());
            denm1 = BigInteger(den.getNumber());

            num = (a*numm1) + numm2;
            den = (a * denm1) + denm2;

            BigInteger breaking = (num*num) - (bigD*den*den);
            if(breaking.getNumber() =="1" && breaking.getIsPositive()){
                break;
            }
        }

        if (pmax < num) {
            pmax = BigInteger(num.getNumber());
            result = D;
        }





    }
    cout << pmax.getNumber()<<endl;
    cout << result <<endl;
}