/**
 * @birth: created by Acathe on 2020-09-28
 * @content:最小生成树
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 5e5 + 5;
constexpr size_t kInf = 0x3f3f3f3f;

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

struct MST: Graph {
    typedef pair<int, int> Pii;
    
    int dist[kMaxV];
    bool vis[kMaxV];

    void addEdge(int u, int v, int w) {
        Graph::addEdge(u, v, w);
        Graph::addEdge(v, u, w);
    }

    int prim() {
        memset(dist, kInf, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        priority_queue<Pii, vector<Pii>, greater<Pii>> q;
        dist[1] = 0;
        q.push({dist[1], 1});
        int res = 0;
        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            res += dist[u];
            for (const auto& i: adj[u]) {
                int v = e[i].v, w = e[i].w;
                if (dist[v] > w) {
                    dist[v] = w;
                    q.push({dist[v], v});
                }
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
