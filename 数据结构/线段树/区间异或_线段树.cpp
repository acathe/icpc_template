/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 区间异或
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr size_t kLogN = 25;

struct BitSegmentTree {
    struct Node {
        int data;
        bool lazy;
    };

    Node node[kMaxN << 2];

    int lSon(int rt) { return rt << 1; }

    int rSon(int rt) { return rt << 1 | 1; }

    void upDate(bool v, int l, int r, int rt) {
        node[rt].lazy ^= v;
        node[rt].data = v ? (r - l + 1) - node[rt].data : node[rt].data;
    }

    void pushUp(int rt) {
        node[rt].data = node[lSon(rt)].data + node[rSon(rt)].data;
    }

    void pushDown(int l, int r, int rt) {
        if (!node[rt].lazy) return;
        int m = (l + r) >> 1;
        upDate(node[rt].lazy, l, m, lSon(rt));
        upDate(node[rt].lazy, m + 1, r, rSon(rt));
        node[rt].lazy = 0;
    }

    void build(int* a, int i, int l, int r, int rt) {
        node[rt].lazy = 0;
        if (l == r) {
            node[rt].data = (a[l] >> i) & 1;
            return;
        }
        int m = (l + r) >> 1;
        build(a, i, l, m, lSon(rt));
        build(a, i, m + 1, r, rSon(rt));
        pushUp(rt);
    }

    void upDate(int L, int R, int v, int l, int r, int rt) {
        if (L <= l && r <= R) return upDate(v, l, r, rt);
        pushDown(l, r, rt);
        int m = (l + r) >> 1;
        if (L <= m) upDate(L, R, v, l, m, lSon(rt));
        if (m < R) upDate(L, R, v, m + 1, r, rSon(rt));
        pushUp(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) return node[rt].data;
        pushDown(l, r, rt);
        int m = (l + r) >> 1;
        int res = 0;
        if (L <= m) res += query(L, R, l, m, lSon(rt));
        if (m < R) res += query(L, R, m + 1, r, rSon(rt));
        return res;
    }
};

struct SegmentTree {
    BitSegmentTree tree[kLogN];

    void build(int* a, int l, int r, int rt) {
        for (int i = 0; i < kLogN; ++i)
            tree[i].build(a, i, l, r, rt);
    }

    void upDate(int L, int R, int v, int l, int r, int rt) {
        for (int i = 0; i < kLogN; ++i)
            tree[i].upDate(L, R, (v >> i) & 1, l, r, rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        int res = 0;
        for (int i = kLogN - 1; i >= 0; i--)
            res = (res << 1) + tree[i].query(L, R, l, r, rt);
        return res;
    }
};

int main() {

    return 0;
}
