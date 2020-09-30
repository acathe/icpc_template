/**
 * @birth: created by Acathe on 2020-09-30
 * @content: 字串哈希
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr uint64_t kSeed = 131;

uint64_t ps[kMaxN];
uint64_t has[kMaxN];

void preHash(const string& s, uint64_t* has) {
    has[0] = 0;
    for (int i = 0; s[i]; i++)
        has[i + 1] = has[i] * kSeed + s[i];
}

inline uint64_t BKDRHash(int l, int r) {
    return has[r + 1] - ps[r - l + 1] * has[l];
}

void table() {
    ps[0] = 1;
    for (int i = 1; i < kMaxN; i++)
        ps[i] = ps[i - 1] * kSeed;
}

int main() {

    return 0;
}
