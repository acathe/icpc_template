/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 树上差分
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
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

struct TreeDiff : LCA {
    int val[kMaxN], par[kMaxN];

    void dfs1(int u) {
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par[u]) continue;
            par[v] = u;
            dfs1(v);
        }
        val[par[u]] += val[u];
    }

    void dfs2(int u) {
        val[u] += val[par[u]];
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par[u]) continue;
            dfs2(v);
        }
    }

    void sigma() {
        par[1] = 0;
        dfs1(1);
        dfs2(1);
    }

    void upDatePath(int x, int y, int v) {
        int xy = lca(x, y);
        val[x] += v;
        val[y] += v;
        val[xy] -= v;
        val[par[xy]] -= v;
    }

    int queryPath(int x, int y) {
        int xy = lca(x, y);
        return val[x] + val[y] - val[xy] - val[par[xy]];
    }
};

int main() {

    return 0;
}
