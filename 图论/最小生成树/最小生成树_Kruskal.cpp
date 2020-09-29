/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 最小生成树
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include<bits/stdc++.h>

using namespace std;

constexpr int kMaxV = 1e5 + 5;

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

struct MST {
    DSU dsu;
    vector<Edge> e;

    void init() { e.clear(); }

    void addEdge(int u, int v, int w) {
        e.push_back({u, v, w});
    }

    int kruskal() {
        dsu.init();
        sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) {
            return a.w < b.w;
        });
        int res = 0;
        for (const auto& ei: e)
            if (dsu.unionXToY(ei.u, ei.v)) res += ei.w;
        return res;
    }
};

int main() {

    return 0;
}
