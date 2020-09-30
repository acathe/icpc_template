/**
 * @birth: created by Acathe on 2020-09-30
 * @content: BKDR Hash
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr uint64_t kSeed = 131;

uint64_t BKDRHash(const string& s) {
    uint64_t res = 0;
    for (int i = 0; s[i]; i++)
        res = res * kSeed + s[i];
    return res;
}

int main() {

    return 0;
}
