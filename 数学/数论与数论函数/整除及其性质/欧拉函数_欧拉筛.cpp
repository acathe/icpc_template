/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 欧拉函数
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e6 + 5;

int prime[kMaxN], cnt;
int phi[kMaxN];
bool vis[kMaxN];

void eulerSieve() {
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    phi[1] = 1;
    vis[0] = vis[1] = true;
    for (int i = 0; i < kMaxN; ++i) {
        if (!vis[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt && i * prime[j] < kMaxN; ++j) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
}

int main() {

    return 0;
}
