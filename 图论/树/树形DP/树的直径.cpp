/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 树的直径
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 1e5 + 5;

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

struct TreeDiam : Graph {
    int dp[kMaxV];
    int diam;

    void addEdge(int u, int v, int w) {
        Graph::addEdge(u, v, w);
        Graph::addEdge(v, u, w);
    }

    void dfs(int u, int par) {
        dp[u] = 0;
        for (const auto& i: adj[u]) {
            int v = e[i].v, w = e[i].w;
            if (v == par) continue;
            dfs(v, u);
            diam = max(diam, dp[u] + w + dp[v]);
            dp[u] = max(dp[u], dp[v] + w);
        }
    }

    int solveTreeDiam() {
        diam = 0;
        dfs(1, 0);
        return diam;
    }
};

int main() {

    return 0;
}
