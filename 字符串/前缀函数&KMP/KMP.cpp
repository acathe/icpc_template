/**
 * @birth: created by Acathe on 2020-09-30
 * @content: KMP
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

int kmp(const string& s, const string& t) {
    prefix(s);
    int res = 0;
    int j = 0;
    for (int i = 0; t[i]; i++) {
        while (j && s[j] != t[i]) j = pi[j - 1];
        j += (s[j] == t[i]);
        res += !s[j];
    }
    return res;
}

int main() {

    return 0;
}
