/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 分组背包
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

int n, m, k;
int w[kMaxN], v[kMaxN];
vector<int> group[kMaxN];
int dp[kMaxN];

void init() {
    memset(dp, 0, sizeof(dp));
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m >> k;
    init();
    for (int i = 0; i < m; ++i) {
        int kind;
        cin >> w[i] >> v[i] >> kind;
        group[kind].push_back(i);
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = n; j >= 0; j--) {
            for (auto it: group[i])
                if (j >= w[it]) dp[j] = max(dp[j], dp[j - w[it]] + v[it]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
