/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 差分数组
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

struct Diff {
    int n, d[kMaxN];

    void init(int* a, int _n) {
        n = _n;
        for (int i = 1; i <= n; ++i)
            d[i] = a[i] - a[i - 1];
    }

    void upDate(int l, int r, int v) {
        d[l] += v;
        d[r + 1] -= v;
    }

    void solve() {
        for (int t = 0; t < 2; t++) {
            for (int i = 1; i <= n; ++i)
                d[i] += d[i - 1];
        }
    }

    int query(int l, int r) { return d[r] - d[l - 1]; }
};

int main() {

    return 0;
}
