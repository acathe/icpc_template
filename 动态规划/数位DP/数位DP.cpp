/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 数位DP
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 25;
constexpr int kCharN = 10;

int a[kMaxN];
int64_t dp[kMaxN][kCharN];

int64_t dfs(int pos, int pre, bool lead, bool limit) {
    if (pos == 0) return 1;
    if (!lead && !limit && dp[pos][pre] != -1) return dp[pos][pre];
    int lim = limit ? a[pos] : 9;
    int64_t res = 0;
    for (int i = 0; i <= lim; ++i) {
        if (i == 4 || !lead && pre == 6 && i == 2) continue;
        res += dfs(pos - 1, i, lead && (i == 0), limit && (i == lim));
    }
    if (!lead && !limit) dp[pos][pre] = res;
    return res;
}

int64_t solve(int64_t x) {
    int id = 0;
    while (x) {
        a[++id] = x % 10;
        x /= 10;
    }
    memset(dp, -1, sizeof(dp));
    return dfs(id, 0, 1, 1);
}

int64_t solve(int64_t l, int64_t r) { return solve(r) - solve(l - 1); }

int main() {

    return 0;
}
