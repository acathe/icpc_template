/**
 * @birth: created by Acathe on 2020-09-28
 * @content: Prufer序列
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
 * @template: https://www.luogu.com.cn/problem/P6086
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 5e6 + 5;

struct Prufer {
    int par[kMaxV], deg[kMaxV];
    int pru[kMaxV];

    void pruferCode(int n) {
        par[n] = 0;
        for (int i = 1; i <= n; ++i)
            deg[i] = 1;
        for (int i = 1; i <= n - 1; ++i)
            ++deg[par[i]];
        int minn = 0;
        while (deg[++minn] != 1) continue;
        int leaf = minn;
        for (int i = 1; i <= n - 2; ++i) {
            pru[i] = par[leaf];
            if (--deg[par[leaf]] == 1 && par[leaf] < minn) {
                leaf = par[leaf];
            } else {
                while (deg[++minn] != 1) continue;
                leaf = minn;
            }
        }
    }

    void pruferDecode(int n) {
        for (int i = 1; i <= n; ++i)
            deg[i] = 1;
        for (int i = 1; i <= n - 2; ++i)
            ++deg[pru[i]];
        int minn = 0;
        while (deg[++minn] != 1) continue;
        int leaf = minn;
        for (int i = 1; i <= n - 2; ++i) {
            par[leaf] = pru[i];
            if (--deg[pru[i]] == 1 && pru[i] < minn) {
                leaf = pru[i];
            } else {
                while (deg[++minn] != 1) continue;
                leaf = minn;
            }
        }
        par[leaf] = n;
        par[n] = 0;
    }
};

int n, m;
Prufer prufer;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n >> m;
    int64_t ans = 0;
    if (m == 1) {
        for (int i = 1; i <= n - 1; ++i) {
            cin >> prufer.par[i];
        }
        prufer.pruferCode(n);
        for (int i = 1; i <= n - 2; ++i)
            ans ^= 1LL * i * prufer.pru[i];
    } else {
        for (int i = 1; i <= n - 2; ++i)
            cin >> prufer.pru[i];
        prufer.pruferDecode(n);
        for (int i = 1; i <= n - 1; ++i)
            ans ^= 1LL * i * prufer.par[i];
    }
    cout << ans << '\n';
    return 0;
}