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
    int bcc[kMaxV], bcc_cnt;
    bool br[kMaxV];

    void addEdge(int u, int v) {
        Graph::addEdge(u, v);
        Graph::addEdge(v, u);
    }

    void tarjan(int u, int par) {
        dfn[u] = low[u] = ++timestamp;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                    br[i] = br[i ^ 1] = true;
            } else if (dfn[v] < dfn[u] && v != par) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    void dfs(int u) {
        bcc[u] = bcc_cnt;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (!br[i] && !bcc[v]) dfs(v);        
        }
    }

    void solveBCC(int n) {
        timestamp = bcc_cnt = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(bcc, 0, sizeof(bcc));
        memset(br, 0, sizeof(br));
        for (int i = 1; i <= n; ++i)
            if (!dfn[i]) tarjan(i, 0);
        for (int i = 1; i <= n; ++i) {
            if (!bcc[i]) {
                ++bcc_cnt;
                dfs(i);
            }
        }
    }
};

int main() {

    return 0;
}
