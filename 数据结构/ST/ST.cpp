/**
 * @birth: created by Acathe on 2020-09-28
 * @content: ST
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: https://www.luogu.com.cn/problem/P3865 时限800ms，测875ms
*/

#include<bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr size_t kLogN = 25;

struct ST {
    int st[kMaxN][kLogN];
    int logb[kMaxN];

    int powb(int x) { return 1 << x; }

    void init(int* a, int n) {
        logb[0] = -1;
        for (int i = 1; i <= n; ++i) {
            logb[i] = logb[i >> 1] + 1;
            st[i][0] = a[i];
        }
        for (int j = 1; j <= logb[n]; ++j) {
            for (int i = 1; i + powb(j) - 1 <= n; ++i)
                st[i][j] = max(st[i][j - 1], st[i + powb(j - 1)][j - 1]);
        }
    }

    int query(int l, int r) {
        int logbn = logb[r - l + 1];
        return max(st[l][logbn], st[r - powb(logbn) + 1][logbn]);
    }
};

int n, m;
int a[kMaxN];
ST st;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    st.init(a, n);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
    return 0;
}