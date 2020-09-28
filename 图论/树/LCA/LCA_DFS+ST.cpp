/**
 * @birth: created by Acathe on 2020-09-28
 * @content: LCA
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: https://www.luogu.com.cn/problem/P3379
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 5e5 + 5; 
constexpr size_t kMaxN = kMaxV * 2;
constexpr size_t kLogN = 25;

struct Edge { int u, v; };

struct Graph {
    vector<int> adj[kMaxV];
    vector<Edge> e;

    void init() {
        e.clear();
        for (auto& i: adj)
            i.clear();
    }

    void addEdge(int u, int v) {
        adj[u].push_back(e.size());
        e.push_back({u, v});
    }
};

struct ST {
    int st[kMaxN][kLogN];
    int logb[kMaxN];

    int powb(int x) { return 1 << x; }
};

struct LCA : Graph, ST {
    int dep[kMaxV];
    int fir[kMaxV], dfn[kMaxN], timestamp;

    void addEdge(int u, int v) {
        Graph::addEdge(u, v);
        Graph::addEdge(v, u);
    }

    void dfs(int u, int par) {
        dep[u] = dep[par] + 1;
        dfn[++timestamp] = u;
        fir[u] = timestamp;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par) continue;
            dfs(v, u);
            dfn[++timestamp] = u;
        }
    }

    int minPos(int x, int y) {
        return dep[dfn[x]] < dep[dfn[y]] ? x : y;
    }

    void solveLCA(int rt) {
        timestamp = 0;
        dep[0] = 0;
        dfs(rt, 0);
        logb[0] = -1;
        for (int i = 1; i <= timestamp; ++i) {
            logb[i] = logb[i >> 1] + 1;
            st[i][0] = i;
        }
        for (int j = 1; j <= logb[timestamp]; ++j) {
            for (int i = 1; i + powb(j) - 1 <= timestamp; ++i)
                st[i][j] = minPos(st[i][j - 1], st[i + powb(j - 1)][j - 1]);
        }
    }

    int lca(int u, int v) {
        if (fir[u] > fir[v]) swap(u, v);
        int lbn = logb[fir[v] - fir[u] + 1];
        return dfn[minPos(st[fir[u]][lbn], st[fir[v] - powb(lbn) + 1][lbn])];
    }
};

int n, m, s;
LCA tree;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m >> s;
    tree.init();
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }
    tree.solveLCA(s);
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << tree.lca(u, v) << '\n';
    }
    return 0;
}