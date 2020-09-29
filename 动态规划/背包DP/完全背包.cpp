/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 完全背包
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

int n, m;
int w[kMaxN], v[kMaxN];
int dp[kMaxN];

void init() {
    memset(dp, 0, sizeof(dp));
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i)
        cin >> w[i] >> v[i];
    for (int i = 0; i < m; ++i) {
        for (int j = w[i]; j <= n; ++j)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
    cout << dp[n] << '\n';
    return 0;
}
