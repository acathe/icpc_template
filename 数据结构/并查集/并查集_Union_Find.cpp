/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 并查集
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: https://www.luogu.com.cn/problem/P3367
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

struct DSU {
    int par[kMaxN];

    void init() {
        for (int i = 0; i < kMaxN; ++i)
            par[i] = i;
    }

    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }

    void unionXToY(int x, int y) {
        par[find(x)] = find(y);
    }
};

int n, m;
DSU dsu;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m;
    dsu.init();
    while (m--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            dsu.unionXToY(u, v);
        } else {
            cout << (dsu.find(u) == dsu.find(v) ? "Y\n" : "N\n");
        }
    }
    return 0;
}