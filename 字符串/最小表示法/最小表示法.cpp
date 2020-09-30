/**
 * @birth: created by Acathe on 2020-09-30
 * @content: 最小表示法
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

int minStr(const string& s) {
    int n = s.length();
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        int cmp = s[(i + k) % n] - s[(j + k) % n];
        if (!cmp) {
            k++;
        } else {
            if (cmp > 0) i += k + 1;
            else j += k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    return min(i, j);
}

int main() {

    return 0;
}
