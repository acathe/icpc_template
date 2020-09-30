/**
 * @birth: created by Acathe on 2020-09-30
 * @content: LIS
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

string s;
int dp[kMaxN];

int lis(const string& s) {
    memset(dp, 0, sizeof(dp));
    int n = s.size();
    dp[0] = s[0] - 'a';
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp, dp + cnt, s[i] - 'a') - dp;
        if (pos < cnt) dp[pos] = s[i] - 'a';
        else dp[cnt++] = s[i] - 'a';
    }
    return cnt;
}

int main() {

    return 0;
}
