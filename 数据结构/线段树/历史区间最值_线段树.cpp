/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 历史区间最值
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr int kInf = 0x3f3f3f3f;

struct SegmentTree {
    struct Node { int maxx, cnt, sec, sum, lazy; };

    Node node[kMaxN << 2];

    int lSon(int rt) { return rt << 1; }

    int rSon(int rt) { return rt << 1 | 1; }

    void update(int v, int l, int r, int rt) {
        if (node[rt].maxx <= v) return;
        node[rt].sum += (v - node[rt].maxx) * node[rt].cnt;
        node[rt].maxx = node[rt].lazy = v;
    }

    void pushUp(int rt) {
        if (node[lSon(rt)].maxx == node[rSon(rt)].maxx) {
            node[rt].maxx = node[lSon(rt)].maxx;
            node[rt].cnt = node[lSon(rt)].cnt + node[rSon(rt)].cnt;
            node[rt].sec = max(node[lSon(rt)].sec, node[rSon(rt)].sec);
        } else if (node[lSon(rt)].maxx > node[rSon(rt)].maxx) {
            node[rt].maxx = node[lSon(rt)].maxx;
            node[rt].cnt = node[lSon(rt)].cnt;
            node[rt].sec = max(node[lSon(rt)].sec, node[rSon(rt)].maxx);
        } else {
            node[rt].maxx = node[rSon(rt)].maxx;
            node[rt].cnt = node[rSon(rt)].cnt;
            node[rt].sec = max(node[lSon(rt)].maxx, node[rSon(rt)].sec);
        }
        node[rt].sum = node[lSon(rt)].sum + node[rSon(rt)].sum;
    }

    void pushDown(int l, int r, int rt) {
        if (node[rt].lazy == -1) return;
        int m = (l + r) >> 1;
        update(node[rt].lazy, l, m, lSon(rt));
        update(node[rt].lazy, m + 1, r, rSon(rt));
        node[rt].lazy = -1;
    }

    void build(int *a, int l, int r, int rt) {
        node[rt].lazy = -1;
        if (l == r) {
            node[rt].maxx = node[rt].sum = a[l];
            node[rt].cnt = 1;
            node[rt].sec = -kInf;
            return;
        }
        int m = (l + r) >> 1;
        build(a, l, m, lSon(rt));
        build(a, m + 1, r, rSon(rt));
        pushUp(rt);
    }

    void update(int L, int R, int v, int l, int r, int rt) {
        if (node[rt].maxx <= v) return;
        if (L <= l && r <= R && node[rt].sec < v)
            return update(v, l, r, rt);
        pushDown(l, r, rt);
        int m = (l + r) >> 1;
        if (L <= m) update(L, R, v, l, m, lSon(rt));
        if (m < R) update(L, R, v, m + 1, r, rSon(rt));
        pushUp(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) return node[rt].sum;
        pushDown(l, r, rt);
        int m = (l + r) >> 1;
        int res = 0;
        if (L <= m) res += query(L, R, l, m, lSon(rt));
        if (m < R) res += query(L, R, m + 1, r, rSon(rt));
        return res;
    }
};

int main() {

    return 0;
}
