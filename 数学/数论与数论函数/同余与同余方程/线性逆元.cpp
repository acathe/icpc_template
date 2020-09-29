/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 线性逆元
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr int kMod = 1e9 + 7;

int64_t inv[kMaxN];

void table() {
    inv[1] = 1;
    for (int i = 2; i < kMaxN; ++i)
        inv[i] = ((kMod - kMod / i) * inv[kMod % i]) % kMod;
}

int main() {

    return 0;
}
