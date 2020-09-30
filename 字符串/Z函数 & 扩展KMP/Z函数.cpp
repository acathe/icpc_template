/**
 * @birth: created by Acathe on 2020-09-30
 * @content: Z函数
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

int z[kMaxN];

void zAlg(const string& s) {
    int l = 0, r = z[0] = 0;
    for (int i = 1; s[i]; i++) {
        z[i] = i <= r ?  min(r - i + 1, z[i - l]) : 0;
        while (s[i + z[i]] && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int main() {

    return 0;
}
