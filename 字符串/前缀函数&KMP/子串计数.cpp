/**
 * @birth: created by Acathe on 2020-09-30
 * @content: 子串计数
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

int calc(string s) {
    reverse(s.begin(), s.end());
    prefix(s);
    int maxx = 0;
    for (int i = 0; s[i]; i++)
        maxx = max(maxx, pi[i]);
    return maxx;
}

int subStrCnt(const string& s) {
    prefix(s);
    int res = 0;
    int n = s.size();
    for (int i = 1; i <= n; i++)
        res += i - calc(s.substr(0, i));
    return res;
}

int main() {

    return 0;
}
