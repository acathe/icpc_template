/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 扫描线
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
 * @template: https://www.luogu.com.cn/problem/P5490
*/

#include<bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = (1e5 + 5) * 4;

struct Map {
    int data[kMaxN], cnt;

    void init() { cnt = 0; }

    void push(int v) { data[cnt++] = v; }

    void solve() {
        sort(data, data + cnt);
        cnt = unique(data, data + cnt) - data;
        for (int i = cnt - 1; i > 0; --i)
            if (data[i] - data[i - 1] > 1) data[cnt++] = data[i - 1] + 1;
        sort(data, data + cnt);
    }

    int rank(int k) { return data[k - 1]; }

    int find(int v) { return lower_bound(data, data + cnt, v) - data + 1; }
};

Map mapp;

struct SegmentTree {
    struct Node { int data, lazy; };

    Node node[kMaxN << 2];

    int lSon(int rt) { return rt << 1; }

    int rSon(int rt) { return rt << 1 | 1; }

    void pushUp(int l, int r, int rt) {
        if (node[rt].lazy) node[rt].data = mapp.rank(r + 1) - mapp.rank(l);
        else if (l == r) node[rt].data = 0; // 真SB，不判叶节点直接走else，可能因为叶节点的lSon和rSon越界RE。
        else node[rt].data = node[lSon(rt)].data + node[rSon(rt)].data;
    }

    void build(int l, int r, int rt) {
        node[rt].data = node[rt].lazy = 0;
        if (l == r) return;
        int m = (l + r) >> 1;
        build(l, m, lSon(rt));
        build(m + 1, r, rSon(rt));
    }

    void update(int L, int R, int v, int l, int r, int rt) {
        if (L <= l && r <= R) {
            node[rt].lazy += v;
            return pushUp(l, r, rt);
        }
        int m = (l + r) >> 1;
        if (L <= m) update(L, R, v, l, m, lSon(rt));
        if (m < R) update(L, R, v, m + 1, r, rSon(rt));
        pushUp(l, r, rt);
    }
};

struct Line { int l, r, h, type; };

int n, cnt;
Line a[kMaxN];
SegmentTree tree;

void init() {
    cnt = 0;
    mapp.init();
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n;
    init();
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[cnt++] = {x1, x2, y1, 1};
        a[cnt++] = {x1, x2, y2, -1};
        mapp.push(x1);
        mapp.push(x2);
    }
    mapp.solve();
    tree.build(1, mapp.cnt - 1, 1);
    sort(a, a + cnt, [](const Line& a, const Line& b) {
        return a.h < b.h;
    });
    int64_t ans = 0;
    for (int i = 0; i < cnt - 1; ++i) {
        tree.update(mapp.find(a[i].l), mapp.find(a[i].r) - 1, a[i].type, 1, mapp.cnt - 1, 1);
        ans += 1LL * tree.node[1].data * (a[i + 1].h - a[i].h);
    }
    cout << ans << '\n';
    return 0;
}
