/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 因子和
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

int sigma(int x) {
    int res = 1;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int sum = 1, mul = 1;
            while (x % i == 0) {
                x /= i;
                mul *= i;
                sum += mul;
            }
            res *= sum;
        }
    }
    if (x != 1) res *= (x + 1);
    return res;
}

int main() {

    return 0;
}
