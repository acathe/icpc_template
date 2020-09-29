/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 归并排序
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

int tmp[kMaxN];

void mergeSort(int* a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) >> 1;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    int p = l, q = m + 1, cnt = l;
    while (p <= m && q <= r) {
        if (a[p] <= a[q]) tmp[cnt++] = a[p++];
        else tmp[cnt++] = a[q++];
    }
    while (p <= m) tmp[cnt++] = a[p++];
    while (q <= r) tmp[cnt++] = a[q++];
    for (int i = l; i <= r; ++i)
        a[i] = tmp[i];
}

int main() {

    return 0;
}
