/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 01背包方案问题
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

int n, m;
int w[kMaxN];
int dp[kMaxN];

void init() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i)
        cin >> w[i];
    for (int i = 0; i < m; ++i) {
        for (int j = n; j >= w[i]; j--)
            dp[j] += dp[j - w[i]];
    }
    cout << dp[n] << '\n';
    return 0;
}
