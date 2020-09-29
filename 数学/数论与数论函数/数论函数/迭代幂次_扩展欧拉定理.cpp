/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 迭代幂次
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

int64_t phi(int64_t x) {
    int64_t res = x;
    for (int64_t i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            res = res / i * (i - 1);
        }
    }
    if (x != 1) res = res / x * (x - 1);
    return res;
}

inline int64_t modu(int64_t x, int mod) {
    return x < mod ? x : x % mod + mod;
}

int64_t quickPow(int64_t x, int64_t p, int mod) {
    int64_t res = 1;
    while (p) {
        if (p & 1) res = modu(res * x, mod);
        p >>= 1;
        x = modu(x * x, mod);
    }
    return res;
}

int64_t exEuler(int64_t x, int64_t p, int mod) {
    if (mod == 1 || p == 1) return modu(x, mod);
    return quickPow(x, exEuler(x, p - 1, phi(mod)), mod);
}

int main() {

    return 0;
}
