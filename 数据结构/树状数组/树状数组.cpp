/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 树状数组
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

struct BIT {
    int n, c[kMaxN];

    int lowBit(int x) { return x & -x; }

    void init(int *a, int n) {
        this->n = n;
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; ++i) {
            c[i] += a[i];
            if (i + lowBit(i) <= n) c[i + lowBit(i)] += c[i];
        }
    }

    void update(int k, int v) {
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

int main() {

    return 0;
}
