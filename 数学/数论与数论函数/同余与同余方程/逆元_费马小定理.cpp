/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 逆元
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int64_t quickPow(int64_t x, int64_t p) {
    int64_t res = 1;
    x %= kMod;
    while (p) {
        if (p & 1) res = (res * x) % kMod;
        p >>= 1;
        x = (x * x) % kMod;
    }
    return res % kMod;
}

inline int64_t inv(int64_t x) { return quickPow(x, kMod - 2); }

int main() {

    return 0;
}
