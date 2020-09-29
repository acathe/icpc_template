/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 基数排序
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr int kRadix = 10;

int tmp[kMaxN];
int buc[kRadix];

void radixSort(int* a, int l, int r) {
    int Max = l;
    for (int i = l; i <= r; ++i)
        Max = a[Max] > a[i] ? Max : i;
    Max = a[Max];
    for (int e = 1; Max / e > 0; e *= kRadix) {
        memset(buc, 0, sizeof(buc));
        for (int i = l; i <= r; ++i)
            buc[(a[i] / e) % kRadix]++;
        for (int i = 1; i < kRadix; ++i)
            buc[i] += buc[i - 1];
        for (int i = r; i >= l; i--)
            tmp[--buc[(a[i] / e) % kRadix]] = a[i];
        for (int i = l; i <= r; ++i)
            a[i] = tmp[i - l];
    }
}

int main() {

    return 0;
}
