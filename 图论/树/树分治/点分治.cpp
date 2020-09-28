/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 点分治
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: http://codeforces.com/problemset/problem/161/D
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

struct TreeCent : Graph {
    int n, siz[kMaxV];
    int cent, dp[kMaxV];
    int vis[kMaxV];

    void dfs(int u, int par) {
        siz[u] = 1;
        dp[u] = 0;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (vis[v] || v == par) continue;
            dfs(v, u);
            siz[u] += siz[v];
            dp[u] = max(dp[u], siz[v]);
        }
        dp[u] = max(dp[u], n - siz[u]);
        if (dp[u] < dp[cent]) cent = u;
    }

    int solveTreeCent(int u, int n) {
        this->n = n;
        cent = 0;
        dfs(u, 0);
        return cent;
    }
};

struct TreeDivide : TreeCent {
    int dist[kMaxV], cnt;
    int k, ans;

    void addEdge(int u, int v, int w) {
        Graph::addEdge(u, v, w);
        Graph::addEdge(v, u, w);
    }

    void dfsDist(int u, int par, int dep) {
        dist[cnt++] = dep;
        for (const auto& i: adj[u]) {
            int v = e[i].v, w = e[i].w;
            if (vis[v] || v == par) continue;
            dfsDist(v, u, dep + w);
        }
    }

    int calc(int u, int dep) {
        cnt = 0;
        dfsDist(u, 0, dep);
        sort(dist, dist + cnt);
        int res = 0;
        for (int i = 0; i < cnt && dist[i] <= k - dist[i]; ++i) {
            int l = lower_bound(dist + i + 1, dist + cnt, k - dist[i]) - dist;
            int r = upper_bound(dist + i + 1, dist + cnt, k - dist[i]) - dist;
            res += r - l;
        }
        return res;
    }

    void dfs(int u) {
        vis[u] = true;
        ans += calc(u, 0);
        for (const auto& i: adj[u]) {
            int v = e[i].v, w = e[i].w;
            if (vis[v]) continue;
            ans -= calc(v, w);
            dfs(solveTreeCent(v, siz[v]));
        }
    }

    int solveVertexDAC(int k, int n) {
        this->k = k;
        ans = 0;
        dp[0] = kInf;
        memset(vis, 0, sizeof(vis));
        dfs(solveTreeCent(1, n));
        return ans;
    }
};

int n, k;
TreeDivide tree;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> k;
    tree.init();
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v, 1);
    }
    cout << tree.solveVertexDAC(k, n) << '\n';
    return 0;
}
