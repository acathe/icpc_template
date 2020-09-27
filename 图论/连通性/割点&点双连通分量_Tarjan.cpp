/**
 * @birth: created by Acathe on 2020-09-27
 * @content: 割点和点双连通分量
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-27
*/

#include <bits/stdc++.h>

using namespace std;

const size_t kMaxV = 1e5 + 5;

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

struct BCC : Graph {
    int dfn[kMaxV], timestamp;
    int low[kMaxV];
    stack<Edge> stk;
    int vis[kMaxV], bcc_cnt;
    vector<int> bcc[kMaxV];
    bool cut[kMaxV];

    void addEdge(int u, int v) {
        Graph::addEdge(u, v);
        Graph::addEdge(v, u);
    }

    void putBcc(int u) {
        if (vis[u] == bcc_cnt) return;
        vis[u] = bcc_cnt;
        bcc[bcc_cnt].push_back(u);
    }

    void tarjan(int u, int par) {
        dfn[u] = low[u] = ++timestamp;
        int child = 0;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (!dfn[v]) {
                stk.push(e[i]);
                ++child;
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) {
                    cut[u] = true;
                    bcc[++bcc_cnt].clear();
                    putBcc(u);
                    putBcc(v);
                    while (stk.top().u != u && stk.top().v != v) {
                        putBcc(stk.top().u);
                        putBcc(stk.top().v);
                        stk.pop();
                    }
                    stk.pop();
                }
            } else if (dfn[v] < dfn[u] && v != par) {
                stk.push(e[i]);
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (par == 0 && child == 1) cut[u] = false;
    }

    void solveBCC(int n) {
        timestamp = bcc_cnt = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(cut, 0, sizeof(cut));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i)
            if (!dfn[i]) tarjan(i, 0);
    }
};

int main() {

    return 0;
}
