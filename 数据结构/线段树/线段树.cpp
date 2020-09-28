/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 线段树
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: https://www.luogu.com.cn/problem/P3372
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

struct SegmentTree {
    struct Node { int64_t data, lazy; };

    Node node[kMaxN << 2];

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

int n, m;
int64_t a[kMaxN];
SegmentTree tree;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    tree.build(a, 1, n, 1);
    while (m--) {
        int op, l, r, v;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> v;
            tree.update(l, r, v, 1, n, 1);
        } else {
            cout << tree.query(l, r, 1, n, 1).data << '\n';
        }
    }
    return 0;
}
