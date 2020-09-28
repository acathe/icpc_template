/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 拓扑排序
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
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

struct TopoSort : Graph {
    int deg[kMaxV];

    void init() {
        Graph::init();
        memset(deg, 0, sizeof(deg));
    }

    void addEdge(int u, int v) {
        Graph::addEdge(u, v);
        ++deg[v];
    }

    bool kahn(vector<int>& order, int n) {
        order.clear();
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            if (!deg[i]) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (const auto& i: adj[u]) {
                int v = e[i].v;
                --deg[v];
                if (!deg[v]) q.push(v);
            }
        }
        return order.size() == n;
    }
};

int main() {

    return 0;
}
