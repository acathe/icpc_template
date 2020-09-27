/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 有向图拓扑排序
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include <bits/stdc++.h>

using namespace std;

const size_t kMaxV = 1e5 + 5;
const size_t kMaxE = 2e5 + 5;

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
    int deg[2][kMaxV];
    int cur[kMaxV];
    bool vis[kMaxE];
    vector<int> path;

    void init(int n) {
        this->n = n;
        Graph::init();
        memset(deg, 0, sizeof(deg));
    }

    void addEdge(int u, int v) {
        ++deg[0][u];
        ++deg[1][v];
        Graph::addEdge(u, v);
    }

    void dfs(int u) {
        for (int& i = cur[u]; i < adj[u].size(); ++i) {
            int v = e[adj[u][i]].v;
            if (vis[i]) continue;
            vis[i] = true;
            dfs(v);
        }
        path.push_back(u);
    }

    bool solveEulerPath() {
        path.clear();
        memset(vis, 0, sizeof(vis));
        memset(cur, 0, sizeof(cur));
        int s, cnt[2] = {};
        for (int i = 1; i <= n; ++i) {
            if (deg[0][i] != deg[1][i]) {
                if (deg[0][i] - deg[1][i] == 1) {
                    s = i;
                    ++cnt[0];
                } else if (deg[1][i] - deg[0][i] == 1) {
                    ++cnt[1];
                } else {
                    return false;
                }
            }
        }
        if (cnt[0] == 0 && cnt[1] == 0) s = 1;
        else if (cnt[0] != 1 && cnt[1] != 1) return false;
        dfs(s);
        reverse(path.begin(), path.end());
        return true;
    }
};

int main() {

    return 0;
}
