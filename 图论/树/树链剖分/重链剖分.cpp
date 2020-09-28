/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 重链剖分
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: https://www.luogu.com.cn/problem/P3384
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 1e5 + 5;

struct SegmentTree {
    struct Node { int64_t data, lazy; };

    Node node[kMaxV << 2];

    int lSon(int rt) { return rt << 1; }

    int rSon(int rt) { return rt << 1 | 1; }

    Node merge(const Node& l, const Node& r) {
        return {l.data + r.data, 0};
    }

    void update(int64_t v, int l, int r, int rt) {
        node[rt].lazy += v;
        node[rt].data += v * (r - l + 1);
    }

    void pushUp(int rt) {
        node[rt] = merge(node[lSon(rt)], node[rSon(rt)]);
    }

    void pushDown(int l, int r, int rt) {
        if (!node[rt].lazy) return;
        int m = (l + r) >> 1;
        update(node[rt].lazy, l, m, lSon(rt));
        update(node[rt].lazy, m + 1, r, rSon(rt));
        node[rt].lazy = 0;
    }

    void build(int64_t* a, int l, int r, int rt) {
        if (l == r) {
            node[rt].data = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(a, l, m, lSon(rt));
        build(a, m + 1, r, rSon(rt));
        pushUp(rt);
    }

    void update(int L, int R, int64_t v, int l, int r, int rt) {
        if (L <= l && r <= R) return update(v, l, r, rt);
        pushDown(l, r, rt);
        int m = (l + r) >> 1;
        if (L <= m) update(L, R, v, l, m, lSon(rt));
        if (m < R) update(L, R, v, m + 1, r, rSon(rt));
        pushUp(rt);
    }

    Node query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) return node[rt];
        pushDown(l, r, rt);
        int m = (l + r) >> 1;
        if (R <= m) return query(L, R, l, m, lSon(rt));
        else if (m < L) return query(L, R, m + 1, r, rSon(rt));
        else return merge(query(L, R, l, m, lSon(rt)), query(L, R, m + 1, r, rSon(rt)));
    }
};

struct Edge{ int u, v; };

struct Graph {
    int64_t w[kMaxV];
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

struct HLD : Graph, SegmentTree {
    int par[kMaxV], top[kMaxV];
    int siz[kMaxV], child[kMaxV];
    int dfn[kMaxV], timestamp;
    int dep[kMaxV];
    int64_t val[kMaxV];

    void addEdge(int u, int v) {
        Graph::addEdge(u, v);
        Graph::addEdge(v, u);
    }

    void dfsChild(int u) {
        dep[u] = dep[par[u]] + 1;
        siz[u] = 1;
        child[u] = 0;
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par[u]) continue;
            par[v] = u;
            dfsChild(v);
            siz[u] += siz[v];
            if (siz[child[u]] < siz[v]) child[u] = v;
        }
    }

    void dfsTop(int u) {
        dfn[u] = ++timestamp;
        val[timestamp] = w[u];
        if (!child[u]) return;
        top[child[u]] = top[u];
        dfsTop(child[u]);
        for (const auto& i: adj[u]) {
            int v = e[i].v;
            if (v == par[u] || v == child[u]) continue;
            top[v] = v;
            dfsTop(v);
        }
    }

    void solveHLD(int rt) {
        siz[0] = 0;
        dep[0] = 1;
        par[rt] = 0;
        dfsChild(rt);
        timestamp = 0;
        top[rt] = rt;
        dfsTop(rt);
        build(val, 1, timestamp, 1);
    }

    void updatePath(int u, int v, int64_t w) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            update(dfn[top[u]], dfn[u], w, 1, timestamp, 1);
            u = par[top[u]];
        }
        if (dfn[u] > dfn[v]) swap(u, v);
        update(dfn[u], dfn[v], w, 1, timestamp, 1);
    }

    Node queryPath(int u, int v) {
        Node u_res, v_res;
        u_res.data = v_res.data = 0;
        while (top[u] != top[v]) {
            if (dep[top[u]] >= dep[top[v]]) {
                u_res = merge(query(dfn[top[u]], dfn[u], 1, timestamp, 1), u_res);
                u = par[top[u]];
            } else {
                v_res = merge(query(dfn[top[v]], dfn[v], 1, timestamp, 1), v_res);
                v = par[top[v]];
            }
        }
        if (dfn[u] >= dfn[v])
            u_res = merge(query(dfn[v], dfn[u], 1, timestamp, 1), u_res);
        else
            v_res = merge(query(dfn[u], dfn[v], 1, timestamp, 1), v_res);
        // u_res = lca -> u, v_res = lca -> v
        // 如果对所合并的值方向有要求，需要把u_res反转为u -> lca
        return merge(u_res, v_res);
    }

    void updateTree(int u, int64_t w) {
        update(dfn[u], dfn[u] + siz[u] - 1, w, 1, timestamp, 1);
    }

    Node queryTree(int u) {
        return query(dfn[u], dfn[u] + siz[u] - 1, 1, timestamp, 1);
    }
};

int n, m, r, p;
HLD tree;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m >> r >> p;
    tree.init();
    for (int i = 1; i <= n; ++i)
        cin >> tree.w[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }
    tree.solveHLD(r);
    while (m--) {
        int op, u, v, w;
        cin >> op >> u;
        if (op == 1) {
            cin >> v >> w;
            tree.updatePath(u, v, w);
        } else if (op == 2) {
            cin >> v;
            cout << tree.queryPath(u, v).data % p << '\n';
        } else if (op == 3) {
            cin >> w;
            tree.updateTree(u, w);
        } else {
            cout << tree.queryTree(u).data % p << '\n';
        }
    }
    return 0;
}
