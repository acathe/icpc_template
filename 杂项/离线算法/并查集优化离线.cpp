/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 并查集优化离线
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

struct Ask { int l, r, id; };

int n, q;
int a[kMaxN];
int r[kMaxN];
Ask ask[kMaxN];
int ans[kMaxN];

int dfs(int L, int R) {
    if (r[L] <= R) {
        a[L] = max(a[L], dfs(r[L], R));
        r[L] = R;
    }
    return a[L];
}

void solve() {
    sort(ask, ask + q, [](const Ask& a, const Ask& b) {
        return a.r < b.r;
    });
    for (int i = 0; i < q; ++i)
        ans[ask[i].id] = dfs(ask[i].l, ask[i].r);
}

void init() {
    for (int i = 0; i <= n; ++i)
        r[i] = i + 1;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> q;
    init();
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < q; ++i) {
        cin >> ask[i].l >> ask[i].r;
        ask[i].id = i;
    }
    solve();
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
    return 0;
}
