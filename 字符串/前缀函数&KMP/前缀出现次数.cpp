/**
 * @birth: created by Acathe on 2020-09-30
 * @content: 前缀出现次数
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

int pi[kMaxN];
int ans[kMaxN];

void prefix(const string& s) {
    pi[0] = 0;
    for (int i = 1; s[i]; i++) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        pi[i] = j + (s[i] == s[j]);
    }
}

void solve(const string& s) {
    prefix(s);
    memset(ans, 0, sizeof(ans));
    int n = s.size();
    for (int i = 0; i < n; i++)
        ans[pi[i]]++;
    for (int i = n - 1; i >= 0; i--)
        ans[pi[i]] += ans[i + 1];
    for (int i = 0; i <= n; i++)
        ans[i]++;
}

int tmp[kMaxN];

void solve(const string& s, const string& t) {
    solve(s);
    int n = s.size();
    for (int i = 1; i <= n; i++)
        tmp[i] = ans[i];
    solve(s + "#" + t);
    for (int i = 1; i <= n; i++)
        ans[i] -= tmp[i];
}

int main() {

    return 0;
}
