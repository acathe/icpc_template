/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 整体二分
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr int kInf = 0x3f3f3f3f;

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


struct Node { int op, l, r, k, v; };

int n, id, q;
int val[kMaxN];
Node a[kMaxN];
BIT tree;
int ans[kMaxN];

Node lTmp[kMaxN], rTmp[kMaxN];

void solve(int l, int r, int L, int R) {
    if (L > R) return;
    if (l == r) {
        for (int i = L; i <= R; ++i)
            if (a[i].op == 2) ans[a[i].v] = l;
        return;
    }
    int mid = (l + r) >> 1;
    int p = 0, q = 0;
    for (int i = L; i <= R; ++i) {
        if (a[i].op == 1) {
            if (a[i].v <= mid) {
                lTmp[p++] = a[i];
                tree.upDate(a[i].l, a[i].k);
            } else {
                rTmp[q++] = a[i];
            }
        } else {
            int k = tree.query(a[i].l, a[i].r);
            if (a[i].k <= k) {
                lTmp[p++] = a[i];
            } else {
                a[i].k -= k;
                rTmp[q++] = a[i];
            }
        }
    }
    for (int i = 0; i < p; ++i) {
        a[L + i] = lTmp[i];
        if (lTmp[i].op == 1) tree.upDate(lTmp[i].l, -lTmp[i].k);
    }
    for (int i = 0; i < q; ++i)
        a[L + p + i] = rTmp[i];
    solve(l, mid, L, L + p - 1);
    solve(mid + 1, r, L + p, R);
}

void init() {
    id = 0;
    tree.init(n);
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> q;
    init();
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
        a[i] = {1, i, i, 1, val[i]};
    }
    while (q--) {
        int op, l, r, k, v;
        cin >> op;
        if (op == 1) {
            cin >> k >> v;
            a[++n] = {1, k, k, -1, val[k]};
            a[++n] = {1, k, k, 1, val[k] = v};
        } else {
            cin >> l >> r >> k;
            a[++n] = {2, l, r, k, id++};
        }
    }
    solve(-kInf, kInf, 1, n);
    for (int i = 0; i < id; ++i)
        cout << ans[i] << '\n';
    return 0;
}
