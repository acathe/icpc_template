/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 逆元
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

int64_t exGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64_t r = exGcd(b, a % b, y, x);
    y -= a / b * x;
    return r;
}

inline int64_t inv(int64_t x) {
    int64_t inv, tmp;
    exGcd(x, MOD, inv, tmp);
    return (inv % MOD + MOD) % MOD;
}

int main() {

    return 0;
}
