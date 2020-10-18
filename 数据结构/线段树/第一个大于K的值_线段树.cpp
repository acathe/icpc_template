/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 第一个大于K的值
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr int kInf = 0x3f3f3f3f;

struct SegmentTree {
    int maxx[kMaxN << 2];

    int lSon(int rt) { return rt << 1; }

    int rSon(int rt) { return rt << 1 | 1; }

    void pushUp(int rt) { maxx[rt] = max(maxx[lSon(rt)], maxx[rSon(rt)]); }

    void build(int l, int r, int rt) {
        maxx[rt] = kInf;
        if (l == r) return;
        int m = (l + r) >> 1;
        build(l, m, lSon(rt));
        build(m + 1, r, rSon(rt));
    }

    void update(int k, int v, int l, int r, int rt) {
        if (l == r) { maxx[rt] = v; return; }
        int m = (l + r) >> 1;
        if (k <= m) update(k, v, l, m, lSon(rt));
        else update(k, v, m + 1, r, rSon(rt));
        pushUp(rt);
    }

    int query(int v, int l, int r, int rt) {
        if (l == r) return maxx[rt] > v ? l : -1;
        int m = (l + r) >> 1;
        if (maxx[lSon(rt)] > v) return query(v, l, m, lSon(rt));
        else if (maxx[rSon(rt)] > v) return query(v, m + 1, r, rSon(rt));
        return -1;
    }

    int query(int k, int v, int l, int r, int rt) {
        if (k == l) return query(v, l, r, rt);
        int m = (l + r) >> 1;
        if (k <= m) {
            int res = query(k, v, l, m, lSon(rt));
            return ~res ? res : query(v, m + 1, r, rSon(rt));
        } else {
            return query(k, v, m + 1, r, rSon(rt));
        }
    }
};

int main() {

    return 0;
}
