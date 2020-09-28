/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 拓扑排序
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

struct TopoSort : Graph {
    int vis[kMaxV];
    vector<int> order;

    bool dfs(int u) {
        vis[u] = 1;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (vis[v] == 1 || !vis[v] && !dfs(v)) return false;
        }
        vis[u] = -1;
        order.push_back(u);
        return true;
    }

    bool solve(int n) {
        order.clear();
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i)
            if (!vis[i] && !dfs(i)) return false;
        reverse(order.begin(), order.end());
        return true;
    }
};

int main() {

    return 0;
}
