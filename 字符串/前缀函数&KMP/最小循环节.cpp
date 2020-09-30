/**
 * @birth: created by Acathe on 2020-09-30
 * @content: 最小循环节
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

int pi[kMaxN];

void prefix(const string& s) {
    pi[0] = 0;
    for (int i = 1; s[i]; i++) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        pi[i] = j + (s[i] == s[j]);
    }
}

int repStr(const string& s) {
    prefix(s);
    int n = s.size();
    if (n % (n - pi[n - 1])) return -1;
    return n - pi[n - 1];
}

int main() {

    return 0;
}
