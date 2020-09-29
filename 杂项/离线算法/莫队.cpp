/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 莫队
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

struct Ask { int l, r, id; };

int n, q;
int a[kMaxN];
int buc[kMaxN], res;
int bl[kMaxN], unit;
Ask ask[kMaxN];
int ans[kMaxN];

void revise(int k, int v) {
    res -= buc[a[k]];
    buc[a[k]] += v;
    res += buc[a[k]];
}

void Mo() {
    sort(ask, ask + q, [](const Ask& a, const Ask& b) {
        return bl[a.l] == bl[b.l] ? a.r < b.r : a.l < b.l;
    });
    int l = 1, r = 0;
    res = 0;
    for (int i = 0; i < q; ++i) {
        while (ask[i].l < l) revise(--l, 1);
        while (l < ask[i].l) revise(l++, -1);
        while (ask[i].r < r) revise(r--, -1);
        while (r < ask[i].r) revise(++r, 1);
        ans[ask[i].id] = res;
    }
}

void init() {
    unit = sqrt(n + 0.5);
    for (int i = 1; i <= n; ++i)
        bl[i] = (i - 1) / unit + 1;
    memset(buc, 0, sizeof(buc));
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> q;
    init();
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < q; ++i) {
        cin >> ask[i].l >> ask[i].r;
        ask[i].id = i;
    }
    Mo();
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
    return 0;
}
