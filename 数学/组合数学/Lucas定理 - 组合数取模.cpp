/**
 * @birth: created by Acathe on 2020-09-29
 * @content: Lucas定理
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr int kMod = 1e9 + 7;

int64_t fact[kMaxN];

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

int64_t C(int64_t r, int64_t n) {
    if (r > n) return 0;
    return (fact[n] * inv(fact[r] * fact[n - r])) % kMod;
}

int64_t lucas(int64_t r, int64_t n) {
    if (r == 0) return 1;
    return (C(r % kMod, n % kMod) * lucas(r / kMod, n / kMod)) % kMod;
}

void table() {
    fact[0] = 1;
    for (int i = 1; i < kMaxN; ++i)
        fact[i] = (fact[i - 1] * i) % kMod;
}

int main() {

    return 0;
}
