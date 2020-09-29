/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 快速排序
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

void quickSort(int* a, int l, int r) {
    if (l >= r) return;
    int p = l, q = r, k = a[l];
    while (p < q) {
        while (k <= a[q] && p < q) q--;
        a[p] = a[q];
        while (a[p] <= k && p < q) p++;
        a[q] = a[p];
    }
    a[p] = k;
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

int main() {

    return 0;
}
