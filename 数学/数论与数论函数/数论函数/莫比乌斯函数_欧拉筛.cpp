/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 莫比乌斯函数
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e6 + 5;

int prime[kMaxN], cnt;
int mu[kMaxN];
bool vis[kMaxN];

void eulerSieve() {
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    mu[1] = 1;
    vis[0] = vis[1] = true;
    for (int i = 0; i < kMaxN; ++i) {
        if (!vis[i]) {
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < cnt && i * prime[j] < kMaxN; ++j) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = mu[i] * mu[prime[j]];
            }
        }
    }
}

int main() {

    return 0;
}
