/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 唯一分解定理
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

int p[kMaxN], a[kMaxN], cnt;

void prime(int x) {
    cnt = 0;
    memset(a, 0, sizeof(a));
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
                a[cnt]++;
            }
            p[cnt++] = i;
        }
    }
    if (x != 1) {
        a[cnt]++;
        p[cnt++] = x;
    }
}

int main() {

    return 0;
}
