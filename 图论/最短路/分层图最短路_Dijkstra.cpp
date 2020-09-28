/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 分层图最短路
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 1e5 + 5;
constexpr size_t kMaxK = 15;
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
    struct Node {
        int u, level, w;

        bool operator<(const Node& cmp) const {
            return w > cmp.w;
        }
    };

    int dist[kMaxV][kMaxK];
    bool vis[kMaxV][kMaxK];

    int dijkstra(int s, int t, int k) {
        memset(dist, kInf, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        priority_queue<Node> q;
        dist[s][0] = 0;
        q.push({s, 0, dist[s][0]});
        while (!q.empty()) {
            int u = q.top().u, level = q.top().level;
            q.pop();
            if (u == t) return dist[u][level];
            if (vis[u][level]) continue;
            vis[u][level] = true;
            for (const auto& i: adj[u]) {
                int v = e[i].v, w = e[i].w;
                if (dist[v][level] > dist[u][level] + w) {
                    dist[v][level] = dist[u][level] + w;
                    q.push({v, level, dist[v][level]});
                }
                if (level < k && dist[v][level + 1] > dist[u][level]) {
                    dist[v][level + 1] = dist[u][level];
                    q.push({v, level + 1, dist[v][level + 1]});
                }
            }
        }
        return -1;
    }
};

int main() {

    return 0;
}
