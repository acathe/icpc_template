/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 负权最短路
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 1e5 + 5;
constexpr int kInf = 0x3f3f3f3f;

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

struct SP: Graph {
    int dist[kMaxV];
    bool vis[kMaxV];
    int path[kMaxV];

    int spfa(int s, int t, int n) {
        memset(dist, kInf, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        dist[s] = 0;
        path[s] = 1;
        q.push(s);
        vis[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (const auto& i: adj[u]) {
                int v = e[i].v, w = e[i].w;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    path[v] = path[u] + 1;
                    if (path[v] > n) return -1;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        return dist[t] == kInf ? -1 : dist[t];
    }
};

int main() {

    return 0;
}
