/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 严格次小生成树
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 1e5 + 5;
constexpr size_t kLogV = 25;
constexpr int kInf = 0x3f3f3f3f;

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

struct LCA : Graph {
    struct SecMax { int maxx, sec; };

    int logbn;
    int dep[kMaxV];
    int par[kMaxV][kLogV];
    SecMax sec_w[kMaxV][kLogV];

    void addEdge(int u, int v, int w) {
        Graph::addEdge(u, v, w);
        Graph::addEdge(v, u, w);
    }

    SecMax merge(const SecMax& a, const SecMax& b) {
        if (a.maxx > b.maxx) return {a.maxx, max(a.sec, b.maxx)};
        else if (a.maxx < b.maxx) return {b.maxx, max(a.maxx, b.sec)};
        else return {a.maxx, max(a.sec, b.sec)};
    }

    void dfs(int u) {
        dep[u] = dep[par[u][0]] + 1;
        for (const auto& i: adj[u]) {
            int v = e[i].v, w = e[i].w;
            if (v == par[u][0]) continue;
            par[v][0] = u;
            sec_w[v][0].maxx = w;
            dfs(v);
        }
    }

    void solveLCA(int rt, int n) {
        dep[0] = 0;
        memset(par, 0, sizeof(par));
        memset(sec_w, -kInf, sizeof(sec_w));
        dfs(rt);
        logbn = log(n + 0.5);
        for (int j = 1; j <= logbn; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (par[i][j - 1]) {
                    par[i][j] = par[par[i][j - 1]][j - 1];
                    sec_w[i][j] = merge(sec_w[i][j - 1], sec_w[par[i][j - 1]][j - 1]);
                }
            }
        }
    }

    int query(int u, int v, int w) {
        if (dep[u] < dep[v]) swap(u, v);
        SecMax res = {-kInf, -kInf};
        for (int i = logbn; i >= 0; --i) {
            if (dep[par[u][i]] >= dep[v]) {
                res = merge(res, sec_w[u][i]);
                u = par[u][i];
            }
        }
        if (u == v) return res.maxx == w ? res.sec : res.maxx;
        for (int i = logbn; i >= 0; --i) {
            if (par[u][i] != par[v][i]) {
                res = merge(res, merge(sec_w[u][i], sec_w[v][i]));
                u = par[u][i];
                v = par[v][i];
            }
        }
        res = merge(res, merge(sec_w[u][0], sec_w[v][0]));
        return res.maxx == w ? res.sec : res.maxx;
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

    bool unionXToY(int x, int y) {
        int xRt = find(x), yRt = find(y);
        if (xRt == yRt) return false;
        par[xRt] = yRt;
        return true;
    }
};

struct MST {
    DSU dsu;
    vector<Edge> e;

    void init() { e.clear(); }

    void addEdge(int u, int v, int w) {
        e.push_back({u, v, w});
    }

    int kruskal(Graph& t) {
        dsu.init();
        sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) {
            return a.w < b.w;
        });
        int res = 0;
        for (const auto& ei: e) {
            if (dsu.unionXToY(ei.u, ei.v)) {
                res += ei.w;
                t.addEdge(ei.u, ei.v, ei.w);
                t.addEdge(ei.v, ei.u, ei.w);
            }
        }
        return res;
    }
};

int n, m;
MST graph;
LCA tree;

int secST() {
    tree.init();
    int value = graph.kruskal(tree);
    tree.solveLCA(1, n);
    int res = kInf;
    for (const auto& ei: graph.e) {
        int u = ei.u, v = ei.v;
        int w = ei.w;
        int sec_w = tree.query(u, v, w);
        if (sec_w >= 0) res = min(res, value - sec_w + w);
    }
    return res;
}

void init() {
    graph.init();
}

int main() {

    return 0;
}
