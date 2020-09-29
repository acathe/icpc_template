/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 多重组合数取模
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

int64_t mulSetA(int* a, int l, int r) {
    int64_t res = 1;
    int cnt = 1;
    for (int i = l + 1; i <= r; ++i) {
        if (a[i] == a[i - 1]) {
            cnt++;
        } else {
            res = (res * fact[cnt]) % kMod;
            cnt = 1;
        }
    }
    return (fact[r - l + 1] * inv((res * fact[cnt]) % kMod)) % kMod;
}

void table() {
    fact[0] = 1;
    for (int i = 1; i < kMaxN; ++i)
        fact[i] = (fact[i - 1] * i) % kMod;
}

int main() {

    return 0;
}
