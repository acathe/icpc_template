/**
 * @birth: created by Acathe on 2020-09-29
 * @content: CDQ分治
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

struct BIT {
    int n;
    int c[kMaxN];

    int lowBit(int x) { return x & -x; }

    void init(int n) {
        this->n = n;
        memset(c, 0, sizeof(c));
    }

    void upDate(int k, int v) {
        for (int i = k; i <= n; i += lowBit(i))
            c[i] += v;
    }

    int query(int k) {
        int res = 0;
        for (int i = k; i > 0; i -= lowBit(i))
            res += c[i];
        return res;
    }

    int query(int l, int r) { return query(r) - query(l - 1); }
};

struct Node {
    int op, x, y, v;

    bool operator<(const Node& cmp) const {
        if (x == cmp.x) return y == cmp.y ? op < cmp.op : y < cmp.y;
        return x < cmp.x;
    }
};

int n, id, q;
BIT tree;
Node a[kMaxN << 2];
int ans[kMaxN], cnt;

Node tmp[kMaxN << 2];

void cdq(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    int p = l, q = mid + 1, cnt = l;
    while (p <= mid && q <= r) {
        if (a[p] < a[q]) {
            if (a[p].op == 1) tree.upDate(a[p].y, a[p].v);
            tmp[cnt++] = a[p++];
        } else {
            if (a[q].op == 2) ans[a[q].v] += tree.query(a[q].y);
            else if (a[q].op == 3) ans[a[q].v] -= tree.query(a[q].y);
            tmp[cnt++] = a[q++];
        }
    }
    while (p <= mid) {
        if (a[p].op == 1) tree.upDate(a[p].y, a[p].v);
        tmp[cnt++] = a[p++];
    }
    while (q <= r) {
        if (a[q].op == 2) ans[a[q].v] += tree.query(a[q].y);
        else if (a[q].op == 3) ans[a[q].v] -= tree.query(a[q].y);
        tmp[cnt++] = a[q++];
    }
    for (int i = l; i <= mid; ++i)
        if (a[i].op == 1) tree.upDate(a[i].y, -a[i].v);
    for (int i = l; i <= r; ++i)
        a[i] = tmp[i];
}

void init() {
    id = cnt = 0;
    tree.init(n);
    memset(ans, 0, sizeof(ans));
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> q;
    init();
    while (q--) {
        int op, x1, y1, x2, y2, v;
        if (op == 1) {
            cin >> x1 >> y1 >> v;
            a[++id] = {op, x1, y1, v};
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            a[++id] = {op, x1 - 1, y1 - 1, cnt};
            a[++id] = {op + 1, x2, y1 - 1, cnt};
            a[++id] = {op + 1, x1 - 1, y2, cnt};
            a[++id] = {op, x2, y2, cnt};
            ++cnt;
        }
    }
    cdq(1, id);
    for (int i = 0; i < cnt; ++i)
        cout << ans[i] << '\n';
    return 0;
}
