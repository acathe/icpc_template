/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 区间筛法
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e6 + 5;

int prime[kMaxN], cnt;
bool vis[kMaxN];

void eulerSieve() {
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    vis[0] = vis[1] = true;
    for (int i = 0; i < kMaxN; ++i) {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] < kMaxN; ++j) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

void sieve(int l, int r) {
    eulerSieve();
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < cnt && prime[i] * prime[i] <= r; ++i) {
        for (int j = (l + prime[i] - 1) / prime[i]; j <= r / prime[i]; ++j)
            vis[j * prime[i] - l] = true;
    }
}

int main() {

    return 0;
}
