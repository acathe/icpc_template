/**
 * @birth: created by Acathe on 2020-09-29
 * @content: Kruskal重构树
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include<bits/stdc++.h>

using namespace std;

constexpr int kMaxV = (1e5 + 5) * 2;

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

struct Edge { int u, v, w; };

struct Graph {
    int w[kMaxV];
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

struct MST {
    vector<Edge> e;
    DSU dsu;

    void addEdge(int u, int v, int w) {
        e.push_back({u, v, w});
    }

    int reKruskal(Graph& tree, int n) {
        dsu.init();
        sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) {
            return a.w < b.w;
        });
        for (const auto& ei: e) {
            if (dsu.find(ei.u) != dsu.find(ei.v)) {
                tree.w[++n] = ei.w;
                tree.addEdge(n, dsu.find(ei.u), 1);
                dsu.unionXToY(dsu.find(ei.u), n);
                tree.addEdge(n, dsu.find(ei.v), 1);
                dsu.unionXToY(dsu.find(ei.v), n);
            }
        }
        return n;
    }
};

int main() {

    return 0;
}
