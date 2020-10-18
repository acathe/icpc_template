/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 块状数组
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr int kSqrtN = 350;

struct Block {
    struct Node { int l, r, sum, lazy; };

    int unit;
    int bl[kMaxN];
    Node block[kSqrtN];
    int data[kMaxN];

    void update(int v, int x) {
        block[x].lazy += v;
        block[x].sum += v * (block[x].r - block[x].l + 1);
    }

    void pushDown(int x) {
        if (!block[x].lazy) return;
        for (int i = block[x].l; i <= block[x].r; ++i)
            data[i] += block[x].lazy;
        block[x].lazy = 0;
    }

    void upDateBlock(int l, int r, int v) {
        for (int i = l; i <= r; ++i) {
            data[i] += v;
            block[bl[i]].sum += v;
        }
    }

    int queryBlock(int l, int r) {
        pushDown(bl[l]);
        int res = 0;
        for (int i = l; i <= r; ++i)
            res += data[i];
        return res;
    }

    void init(int *a, int n) {
        memset(block, 0, sizeof(block));
        unit = sqrt(n + 0.5);
        for (int i = 1; i <= n; ++i) {
            bl[i] = (i - 1) / unit + 1;
            if (bl[i] != bl[i - 1]) block[bl[i]].l = i;
            block[bl[i]].r = i;
        }
        for (int i = 1; i <= n; ++i) {
            data[i] = a[i];
            block[bl[i]].sum += a[i];
        }
    }

    void update(int l, int r, int v) {
        if (bl[l] == bl[r]) return upDateBlock(l, r, v);
        upDateBlock(l, block[bl[l]].r, v);
        for (int i = bl[l] + 1; i <= bl[r] - 1; ++i)
            update(v, i);
        upDateBlock(block[bl[r]].l, r, v);
    }

    int query(int l, int r) {
        if (bl[l] == bl[r]) return queryBlock(l, r);
        int res = 0;
        res += queryBlock(l, block[bl[l]].r);
        for (int i = bl[l] + 1; i <= bl[r] - 1; ++i)
            res += block[i].sum;
        res += queryBlock(block[bl[r]].l, r);
        return res;
    }
};

int main() {

    return 0;
}
