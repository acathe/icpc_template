/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 最大流
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: https://www.luogu.com.cn/problem/P3376
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 205;
constexpr int64_t kInf = 0x3f3f3f3f3f3f3f3fLL;

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

struct NetworkFlow : Graph {
    int cur[kMaxV];
    int dep[kMaxV];

    void addEdge(int u, int v, int f) {
        Graph::addEdge(u, v, f);
        Graph::addEdge(v, u, 0);
    }

    bool bfs(int s, int t) {
        memset(dep, 0, sizeof(dep));
        queue<int> q;
        dep[s] = 1;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) return true;
            for (const auto& i: adj[u]) {
                int v = e[i].v, w = e[i].w;
                if (!dep[v] && w) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return false;
    }

    int64_t dfs(int u, int64_t limit, int t) {
        if (u == t) return limit;
        int64_t res = 0;
        for (int& i = cur[u]; i < adj[u].size(); ++i) {
            int v = e[adj[u][i]].v, w = e[adj[u][i]].w;
            if (w && dep[v] == dep[u] + 1) {
                int64_t f = dfs(v, min(limit - res, (int64_t)w), t);
                e[adj[u][i]].w -= f;
                e[adj[u][i] ^ 1].w += f;
                res += f;
                if (res == limit) return res;
            }
        }
        return res;
    }

    int64_t dinic(int s, int t) {
        int64_t res = 0;
        while (bfs(s, t)) {
            memset(cur, 0, sizeof(cur));
            res += dfs(s, kInf, t);
        }
        return res;
    }
};

int n, m, s, t;
NetworkFlow graph;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m >> s >> t;
    graph.init();
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    cout << graph.dinic(s, t) << '\n';
    return 0;
}