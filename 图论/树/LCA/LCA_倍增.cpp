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
constexpr size_t kLogV = 25;

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

struct LCA : Graph {
    int logbn;
    int dep[kMaxV];
    int par[kMaxV][kLogV];

    void addEdge(int u, int v) {
        Graph::addEdge(u, v);
        Graph::addEdge(v, u);
    }

    void dfs(int u) {
        dep[u] = dep[par[u][0]] + 1;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par[u][0]) continue;
            par[v][0] = u;
            dfs(v);
        }
    }

    void solveLCA(int rt, int n) {
        dep[0] = 0;
        memset(par, 0, sizeof(par));
        dfs(rt);
        logbn = log(n + 0.5);
        for (int j = 1; j <= logbn; ++j) {
            for (int i = 1; i <= n; ++i)
                if (par[i][j - 1]) par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }

    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = logbn; i >= 0; --i)
            if (dep[par[u][i]] >= dep[v]) u = par[u][i];
        if (u == v) return u;
        for (int i = logbn; i >= 0; --i) {
            if (par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        }
        return par[u][0];
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
    tree.solveLCA(s, n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << tree.lca(u, v) << '\n';
    }
    return 0;
}