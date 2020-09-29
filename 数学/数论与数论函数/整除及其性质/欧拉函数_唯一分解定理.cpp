/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 欧拉函数
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

int phi(int x) {
    int res = x;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            res = res / i * (i - 1);
        }
    }
    if (x != 1) res = res / x * (x - 1);
    return res;
}

int main() {

    return 0;
}
