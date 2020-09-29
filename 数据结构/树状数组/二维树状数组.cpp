/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 二维树状数组
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1500;

struct BIT2D {
    int n, m;
    int c[kMaxN][kMaxN];

    int lowBit(int x) { return x & -x; }

    void init(int n, int m) {
        this->n = n;
        this->m = m;
        memset(c, 0, sizeof(c));
    }

    void upDate(int x, int y, int v) {
        for (int i = x; i <= n; i += lowBit(i)) {
            for (int j = y; j <= m; j += lowBit(j))
                c[i][j] += v;
        }
    }

    int query(int x, int y) {
        int res = 0;
        for (int i = x; i > 0; i -= lowBit(i)) {
            for (int j = y; j > 0; j -= lowBit(j))
                res += c[i][j];
        }
        return res;
    }

    int query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};

int main() {

    return 0;
}
