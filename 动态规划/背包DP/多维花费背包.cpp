/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 多维花费背包
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1005;

int n1, n2, m;
int w1[kMaxN], w2[kMaxN], v[kMaxN];
int dp[kMaxN][kMaxN];

void init() {
    memset(dp, 0, sizeof(dp));
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n1 >> n2 >> m;
    init();
    for (int i = 0; i < m; ++i)
        cin >> w1[i] >> w2[i] >> v[i];
    for (int k = 0; k < m; k++) {
        for (int i = n1; i >= w1[k]; i--) {
            for (int j = n2; j >= w2[k]; j--)
                dp[i][j] = max(dp[i][j], dp[i - w1[k]][j - w2[k]] + v[k]);
        }
    }
    cout << dp[n1][n2] << '\n';
    return 0;
}
