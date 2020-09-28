/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 费用流
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: https://www.luogu.com.cn/problem/P3381
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 5005;
constexpr int kInf = 0x3f3f3f3f;

struct Edge { int u, v, w, c; };

struct Graph {
    vector<int> adj[kMaxV];
    vector<Edge> e;

    void init() {
        e.clear();
        for (auto& i: adj)
            i.clear();
    }

    void addEdge(int u, int v, int w, int c) {
        adj[u].push_back(e.size());
        e.push_back({u, v, w, c});
    }
};

struct CostFlow: Graph {
    int dist[kMaxV];
    int vis[kMaxV];
    int pre[kMaxV];

    void addEdge(int u, int v, int w, int c) {
        Graph::addEdge(u, v, w, c);
        Graph::addEdge(v, u, 0, -c);
    }

    int spfa(int s, int t) {
        memset(vis, 0, sizeof(vis));
        memset(dist, kInf, sizeof(dist));
        queue<int> q;
        dist[s] = 0;
        pre[s] = 0;
        q.push(s);
        vis[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (const auto& i: adj[u]) {
                int v = e[i].v, w = e[i].w, c = e[i].c;
                if (w && dist[v] > dist[u] + c) {
                    dist[v] = dist[u] + c;
                    pre[v] = i;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        return dist[t];
    }

    int mcmf(int s, int t, int& f) {
        int res = f = 0;
        while (spfa(s, t) != kInf) {
            int flow = kInf;
            for (int i = t; i != s; i = e[pre[i]].u)
                flow = min(flow, e[pre[i]].w);
            for (int i = t; i != s; i = e[pre[i]].u) {
                e[pre[i]].w -= flow;
                e[pre[i] ^ 1].w += flow;
            }
            f += flow;
            res += flow * dist[t];
        }
        return res;
    }
};

int n, m, s, t;
CostFlow graph;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m >> s >> t;
    graph.init();
    while (m--) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        graph.addEdge(u, v, w, c);
    }
    int f;
    int c = graph.mcmf(s, t, f);
    cout << f << ' ' << c << '\n';
    return 0;
}