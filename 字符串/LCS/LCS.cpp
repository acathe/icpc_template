/**
 * @birth: created by Acathe on 2020-09-30
 * @content: LCS
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1005;

string s, t;
int dp[kMaxN][kMaxN];

int lcs(const string& s, const string& t) {
    memset(dp, 0, sizeof(dp));
    int n = s.size(), m = t.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    return dp[n][m];
}

int main() {

	return 0;
}
