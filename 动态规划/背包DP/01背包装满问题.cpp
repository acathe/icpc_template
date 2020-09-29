/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 01背包装满问题
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr int kInf = 0x3f3f3f3f;

int n, m;
int w[kMaxN], v[kMaxN];
int dp[kMaxN];

void init() {
    memset(dp, -kInf, sizeof(dp));
    dp[0] = 0;
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
        for (int j = n; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
    cout << (dp[n] > 0 ? dp[n] : -1) << '\n';
    return 0;
}
