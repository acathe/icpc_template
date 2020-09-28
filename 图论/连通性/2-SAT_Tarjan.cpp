/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 2-SAT
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: https://www.luogu.com.cn/problem/P4782
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 1e6 + 5;
constexpr size_t kStatus = 2;

struct Edge { int u, v; };

struct Graph {
    vector<int> adj[kMaxV * kStatus];
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

struct BSAT : Graph {
    int id[kMaxV][kStatus];
    int dfn[kMaxV * kStatus], timestamp;
    int low[kMaxV * kStatus];
    stack<int> stk;
    int scc[kMaxV * kStatus], scc_cnt;
    bool ans[kMaxV];

    void init(int n) {
        Graph::init();
        int idx = 0;
        for (int i = 1; i <= n; ++i) {
            id[i][0] = ++idx;
            id[i][1] = ++idx;
        }
    }

    void andVar(int u, bool x, int v, bool y) {
        addEdge(id[u][x], id[v][y]);
        addEdge(id[v][y ^ 1], id[u][x ^ 1]);
    }

    void orVar(int u, bool x, int v, bool y) {
        addEdge(id[u][x ^ 1], id[v][y]);
        addEdge(id[v][y ^ 1], id[u][x]);
    }

    void trueVar(int u, bool x) {
        addEdge(id[u][x ^ 1], id[u][x]);
    }

    void tarjan(int u) {
        dfn[u] = low[u] = ++timestamp;
        stk.push(u);
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (!dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (!scc[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            scc[u] = ++scc_cnt;
            while (stk.top() != u) {
                scc[stk.top()] = scc_cnt;
                stk.pop();
            }
            stk.pop();
        }
    }

    bool solveBSAT(int n) {
        timestamp = scc_cnt = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(scc, 0, sizeof(scc));
        for (int i = 1; i <= n * kStatus; ++i)
            if (!dfn[i]) tarjan(i);
        for (int i = 1; i <= n; ++i)
            if (scc[id[i][0]] == scc[id[i][1]]) return false;
        for (int i = 1; i <= n; ++i)
            ans[i] = (scc[id[i][0]] > scc[id[i][1]]);
        return true;
    }
};

int n, m;
BSAT graph;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m;
    graph.init(n);
    while (m--) {
        int u, v;
        bool x, y;
        cin >> u >> x >> v >> y;
        graph.orVar(u, x, v, y);
    }
    if (graph.solveBSAT(n)) {
        cout << "POSSIBLE\n";
        for (int i = 1; i <= n; ++i)
            cout << graph.ans[i] << ' ';
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
