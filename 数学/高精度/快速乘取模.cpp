/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 快速乘取模
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t MOD = 1000000000000000007LL;

inline int64_t mul(int64_t x, int64_t y) {
    x %= MOD;
    y %= MOD;
    return (x * y - int64_t((long double)x * y / MOD) * MOD + MOD) % MOD;
}

int main() {

    return 0;
}
