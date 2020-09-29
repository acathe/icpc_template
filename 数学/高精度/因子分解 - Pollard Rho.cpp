/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 因子分解
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(0));

inline int64_t mul(int64_t x, int64_t y, int64_t MOD) {
    x %= MOD;
    y %= MOD;
    return (x * y - int64_t((long double)x * y / MOD) * MOD + MOD) % MOD;
}

int64_t pollardRho(int64_t x) {
    if (x == 1) return 1;
    int64_t s = 0, t = 0, c = 1LL * rnd() % (x - 1) + 1;
    for (int i = 1; ; i <<= 1) {
        int64_t val = 1;
        for (int j = 1; j <= i; ++j) {
            t = (mul(t, t, x) + c) % x;
            val = mul(val, abs(t - s), x);
            if (j % 127 == 0) {
                int64_t d = __gcd(val, x);
                if (d > 1) return d;
            }
        }
        int64_t d = __gcd(val, x);
        if (d > 1) return d;
        s = t;
    }
}

int main() {

    return 0;
}
