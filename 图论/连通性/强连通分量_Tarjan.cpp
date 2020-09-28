/**
 * @birth: created by Acathe on 2020-09-27
 * @content: 强连通分量
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-27
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

struct SCC : Graph {
    int dfn[kMaxV], timestamp;
    int low[kMaxV];
    stack<int> stk;
    int scc[kMaxV], scc_cnt;

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

    void solveSCC(int n) {
        timestamp = scc_cnt = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(scc, 0, sizeof(scc));
        for(int i = 1; i <= n; ++i)
            if(!dfn[i]) tarjan(i);
    }
};

int main() {

    return 0;
}
