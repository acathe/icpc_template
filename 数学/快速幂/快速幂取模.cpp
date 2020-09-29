/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 快速幂取模
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

int64_t quickPow(int64_t x, int64_t p) {
    int64_t res = 1;
    x %= MOD;
    while (p) {
        if (p & 1) res = (res * x) % MOD;
        p >>= 1;
        x = (x * x) % MOD;
    }
    return res % MOD;
}

int main() {

    return 0;
}
