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

struct Edge { int u, v, w; };

struct Graph {
    vector<int> adj[kMaxV];
    vector<Edge> e;

    void init() {
        e.clear();
        for (auto& i: adj)
            i.clear();
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(e.size());
        e.push_back({u, v, w});
    }
};

struct DSU {
    int par[kMaxV];

    void init() {
        for (int i = 0; i < kMaxV; ++i)
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

struct LCA : Graph {
    bool vis[kMaxV];
    DSU dsu;
    Graph ask;
    int ans[kMaxV];

    void init() {
        Graph::init();
        ask.init();
    }

    void addEdge(int u, int v) {
        Graph::addEdge(u, v, 1);
        Graph::addEdge(v, u, 1);
    }

    void addAsk( int idx, int u, int v) {
        ask.addEdge(u, v, idx);
        ask.addEdge(v, u, idx);
    }

    void tarjan(int u, int par) {
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par) continue;
            tarjan(v, u);
            dsu.unionXToY(v, u);
            vis[v] = true;
        }
        for (const auto& i: ask.adj[u]) {
            int v = ask.e[i].v, id = ask.e[i].w;
            if (vis[v]) ans[id] = dsu.find(v);
        }
    }

    void solveLCA(int rt) {
        dsu.init();
        memset(vis, 0, sizeof(vis));
        tarjan(rt, 0);
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
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        tree.addAsk(i, u, v);
    }
    tree.solveLCA(s);
    for (int i = 0; i < m; ++i)
        cout << tree.ans[i] << '\n';
    return 0;
}