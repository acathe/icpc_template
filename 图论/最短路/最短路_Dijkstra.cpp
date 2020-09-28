/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 最短路
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: https://www.luogu.com.cn/problem/P4779
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

    int dist[kMaxV];
    bool vis[kMaxV];

    void dijkstra(int s) {
        memset(dist, kInf, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        priority_queue<Pii, vector<Pii>, greater<Pii>> q;
        dist[s] = 0;
        q.push({dist[s], s});
        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (const auto& i: adj[u]) {
                int v = e[i].v, w = e[i].w;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push({dist[v], v});
                }
            }
        }
    }
};

int n, m, s;
SP graph;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m >> s;
    graph.init();
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    graph.dijkstra(s);
    for (int i = 1; i <= n; ++i)
        cout << graph.dist[i] << ' ';
    cout << '\n';
    return 0;
}