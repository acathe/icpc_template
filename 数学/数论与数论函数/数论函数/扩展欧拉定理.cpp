/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 扩展欧拉定理
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

inline int64_t mod(int64_t x, int MOD) {
    return x < MOD ? x : x % MOD + MOD;
}

int64_t quickPow(int64_t x, int64_t p, int MOD) {
    int64_t res = 1;
    while (p) {
        if (p & 1) res = mod(res * x, MOD);
        p >>= 1;
        x = mod(x * x, MOD);
    }
    return res;
}

inline int64_t exEuler(int64_t x, int64_t p, int MOD) {
    return quickPow(x, mod(p, phi(MOD)), MOD);
}

int main() {

    return 0;
}
