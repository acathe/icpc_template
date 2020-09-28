/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 次短路
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
    typedef pair<int, int> Pii;

    int dist[2][kMaxV];
    bool vis[kMaxV];

    void addEdge(int u, int v, int w) {
        Graph::addEdge(u, v, w);
        Graph::addEdge(v, u, w);
    }

    void dijkstra(int s, int tim) {
        memset(dist[tim], kInf, sizeof(dist[tim]));
        memset(vis, 0, sizeof(vis));
        priority_queue<Pii, vector<Pii>, greater<Pii>> q;
        dist[tim][s] = 0;
        q.push({dist[tim][s], s});
        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (const auto& i: adj[u]) {
                int v = e[i].v, w = e[i].w;
                if (dist[tim][v] > dist[tim][u] + w) {
                    dist[tim][v] = dist[tim][u] + w;
                    q.push({dist[tim][v], v});
                }
            }
        }
    }

    int secSP(int s, int t) {
        dijkstra(s, 0);
        dijkstra(t, 1);
        int res = kInf;
        for (const auto& ei: e) {
            int u = ei.u, v = ei.v, w = ei.w;
            if (dist[0][t] < dist[0][u] + w + dist[1][v])
                res = min(res, dist[0][u] + w + dist[1][v]);
        }
        return res;
    }
};

int main(){

    return 0;
}
