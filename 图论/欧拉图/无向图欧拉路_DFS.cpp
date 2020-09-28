/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 无向图拓扑排序
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 1e5 + 5;
constexpr size_t kMaxE = 2e5 + 5;

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

struct EulerPath : Graph {
    int n;
    int deg[kMaxV];
    int cur[kMaxV];
    bool vis[kMaxE];
    vector<int> path;

    void init(int n) {
        this->n = n;
        Graph::init();
        memset(deg, 0, sizeof(deg));
    }

    void addEdge(int u, int v) {
        ++deg[u];
        ++deg[v];
        Graph::addEdge(u, v);
        Graph::addEdge(v, u);
    }

    void dfs(int u) {
        for (int& i = cur[u]; i < adj[u].size(); ++i) {
            int v = e[adj[u][i]].v;
            if (vis[i]) continue;
            vis[i] = vis[i ^ 1] = true;
            dfs(v);
        }
        path.push_back(u);
    }

    bool solveEulerPath() {
        path.clear();
        memset(vis, 0, sizeof(vis));
        memset(cur, 0, sizeof(cur));
        int s, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (deg[i] & 1) {
                s = i;
                ++cnt;
            }
        }
        if (cnt == 0) s = 1;
        else if (cnt != 2) return false;
        dfs(s);
        reverse(path.begin(), path.end());
        return true;
    }
};

int main() {

    return 0;
}
