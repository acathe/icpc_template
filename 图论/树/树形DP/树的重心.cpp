/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 树的重心
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 1e5 + 5;
constexpr int kInf = 0x3f3f3f3f;

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

struct TreeCent : Graph {
    int n, siz[kMaxV];
    int cent, dp[kMaxV];

    void addEdge(int u, int v) {
        Graph::addEdge(u, v);
        Graph::addEdge(v, u);
    }

    void dfs(int u, int par) {
        siz[u] = 1;
        dp[u] = 0;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par) continue;
            dfs(v, u);
            siz[u] += siz[v];
            dp[u] = max(dp[u], siz[v]);
        }
        dp[u] = max(dp[u], n - siz[u]);
        if (dp[u] < dp[cent]) cent = u;
    }

    int solveTreeCent(int n) {
        this->n = n;
        cent = 0;
        dp[0] = kInf;
        dfs(1, 0);
        return cent;
    }
};

int main() {

    return 0;
}
