/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 多重背包
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

int n, m;
int w[kMaxN], v[kMaxN], c[kMaxN];
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
        cin >> w[i] >> v[i] >> c[i];
    for (int i = 0; i < m; ++i) {
        for (int k = 1; k < c[i]; k <<= 1) {
            for (int j = n; j >= k * w[i]; j--)
                dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
            c[i] -= k;
        }
        for (int j = n; j >= c[i] * w[i]; j--)
            dp[j] = max(dp[j], dp[j - c[i] * w[i]] + c[i] * v[i]);
    }
    cout << dp[n] << '\n';
    return 0;
}
