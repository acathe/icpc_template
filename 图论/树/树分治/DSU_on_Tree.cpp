/**
 * @birth: created by Acathe on 2020-09-28
 * @content: DSU on Tree
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: http://codeforces.com/problemset/problem/600/E
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 1e5 + 5;

struct Edge { int u, v; };

struct Graph {
    int w[kMaxV];
    vector<int> adj[kMaxV];
    vector<Edge> e;

    void init() {
        e.clear();
        memset(w, 0, sizeof(w));
        for (auto& i: adj)
            i.clear();
    }

    void addEdge(int u, int v) {
        adj[u].push_back(e.size());
        e.push_back({u, v});
    }
};

struct DsuOnTree : Graph {
    int siz[kMaxV], child[kMaxV];
    int buc[kMaxV], maxx;
    int64_t ans[kMaxV], res;

    void addEdge(int u, int v) {
        Graph::addEdge(u, v);
        Graph::addEdge(v, u);
    }

    void dfsChild(int u, int par){
        child[u] = 0;
        siz[u] = 1;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par) continue;
            dfsChild(v, u);
            siz[u] += siz[v];
            if (siz[child[u]] < siz[v]) child[u] = v;
        }
    }

    void modify(int k, int v) {
        buc[k] += v;
        if (maxx < buc[k]) {
            maxx = buc[k];
            res = k;
        } else if (maxx == buc[k]) {
            res += k;
        }
    }

    void update(int u, int par, int val) {
        modify(w[u], val);
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par) continue;
            update(v, u, val);
        }
    }

    void dfs(int u, int par) {
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par || v == child[u]) continue;
            dfs(v, u);
        }
        if (child[u]) dfs(child[u], u);
        modify(w[u], 1);
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par || v == child[u]) continue;
            update(v, u, 1);
        }
        ans[u] = res;
        if (u != child[par]) {
            update(u, par, -1);
            maxx = res = 0;
        }
    }

    void solveDsuOnTree() {
        res = 0;
        siz[0] = 0;
        memset(buc, 0, sizeof(buc));
        dfsChild(1, 0);
        dfs(1, 0);
    }
};

int n;
DsuOnTree tree;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n;
    tree.init();
    for (int i = 1; i <= n; ++i)
        cin >> tree.w[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }
    tree.solveDsuOnTree();
    for (int i = 1; i <= n; ++i)
        cout << tree.ans[i] << ' ';
    cout << '\n';
    return 0;
}
