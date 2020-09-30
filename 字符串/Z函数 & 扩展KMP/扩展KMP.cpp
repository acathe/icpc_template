/**
 * @birth: created by Acathe on 2020-09-30
 * @content: 扩展KMP
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

int z[kMaxN];
int extend[kMaxN];

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

void exKmp(const string& s, const string& t) {
    zAlg(s);
    int l = -1, r = -1;
    for (int i = 0; t[i]; i++) {
        extend[i] = i <= r ? min(r - i + 1, z[i - l]) : 0;
        while (s[extend[i]] && t[i + extend[i]] && s[extend[i]] == t[i + extend[i]])
            extend[i]++;
        if (i + extend[i] - 1 > r) {
            l = i;
            r = i + extend[i] - 1;
        }
    }
}

int main() {

    return 0;
}
