/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 树的最大独立集
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 1e5 + 5;

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

struct TreeDP : Graph {
    int dp[kMaxV][2];

    void addEdge(int u, int v) {
        Graph::addEdge(u, v);
        Graph::addEdge(v, u);
    }

    void dfs(int u, int par) {
        dp[u][0] = 0;
        dp[u][1] = 1;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par) continue;
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }

    int solveTreeDP() {
        dfs(1, 0);
        return max(dp[1][0], dp[1][1]);
    }
};

int main() {

    return 0;
}
