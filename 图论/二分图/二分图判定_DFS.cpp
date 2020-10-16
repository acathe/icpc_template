/**
 * @birth: created by Acathe on 2020-09-24
 * @content: 二分图判定
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-27
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

struct BG : Graph {
    bool vis[kMaxV];
    int color[kMaxV];

    void addEdge(int u, int v) {
        Graph::addEdge(u, v);
        Graph::addEdge(v, u);
    }

    bool dfs(int u) {
        vis[u] = true;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (!vis[v]) {
                color[v] = 1 - color[u];
                if (!dfs(v)) return false;
            } else if (color[u] == color[v]) {
                return false;
            }
        }
        return true;
    }

    bool isBG(int n) {
        memset(vis, 0, sizeof(vis));
        memset(color, 0, sizeof(color));
        for (int i = 1; i <= n; ++i)
            if (!vis[i] && !dfs(i)) return false;
        return true;
    }
};

int main() {

    return 0;
}
