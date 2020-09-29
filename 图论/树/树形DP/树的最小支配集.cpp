/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 树的最小支配集
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
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

/**
 * 0：不在支配集中且被子节点覆盖
 * 1：在支配集中
 * 2：不在支配集中且被父节点覆盖
*/
struct TreeDP : Graph {
    int dp[kMaxV][3];

    void addEdge(int u, int v) {
        Graph::addEdge(u, v);
        Graph::addEdge(v, u);
    }

    int dfs(int u, int par) {
        dp[u][1] = 1;
        dp[u][2] = 0;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par) continue;
            dfs(v, u);
            dp[u][1] += min(dp[v][0], min(dp[v][1], dp[v][2]));
            dp[u][2] += min(dp[v][0], dp[v][1]);
        }
        dp[u][0] = kInf;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par) continue;
            dp[u][0] = min(dp[u][0], dp[u][2] - min(dp[v][0], dp[v][1]) + dp[v][1]);
        }
        return min(dp[u][0], dp[u][1]);
    }
};

int main() {

    return 0;
}
