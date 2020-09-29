/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 状压DP
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 15;

int n, m;
int a[kMaxN];
int dp[kMaxN][1 << kMaxN];
int start;

void dfs(int i, int j, int now, int next) {
    if (j == m) {
        dp[i + 1][next] += dp[i][start];
        return;
    }
    dfs(i, j + 1, now, next);
    if (!(now & (1 << j))) dfs(i, j + 1, now | (3 << j), next | (1 << j));
}

void init() {
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m;
    init();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool x;
            cin >> x;
            a[i] = a[i] << 1 | x;
        }
    }
    dp[0][a[0]] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << m); ++j) {
            if (dp[i][j]) {
                start = j;
                dfs(i, 0, j, a[i + 1]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << m); ++i)
        ans += dp[n][i];
    cout << ans << '\n';
    return 0;
}
