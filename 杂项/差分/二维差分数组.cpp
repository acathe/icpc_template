/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 二位差分数组
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1005;

struct Diff2D {
    int n, m;
    int d[kMaxN][kMaxN];

    void init(int n, int m) {
        this->n = n;
        this->m = m;
        memset(d, 0, sizeof(d));
    }

    void upDate(int x1, int y1, int x2, int y2, int v) {
        d[x1][y1] += 1;
        d[x2 + 1][y1] -= 1;
        d[x1][y2 + 1] -= 1;
        d[x2 + 1][y2 + 1] += 1;
    }

    void solve() {
        for (int t = 0; t < 2; t++) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j)
                    d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            }
        }
    }

    int query(int x1, int y1, int x2, int y2) {
        return d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1];
    }
};

int main() {

    return 0;
}
