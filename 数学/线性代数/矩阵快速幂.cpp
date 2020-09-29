/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 矩阵快速幂
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int kMatN = 105;
constexpr int kMod = 1e9 + 7;

struct Matrix {
    int64_t m[kMatN][kMatN];

    void init(int x) {
        memset(m, 0, sizeof(m));
        for (int i = 0; i < kMatN; ++i)
            m[i][i] = x;
    }

    Matrix operator*(const Matrix& a) const {
        Matrix res;
        res.init(0);
        for (int i = 0; i < kMatN; ++i) {
            for (int k = 0; k < kMatN; k++) {
                for (int j = 0; j < kMatN; ++j)
                    res.m[i][j] = (res.m[i][j] + (m[i][k] * a.m[k][j]) % kMod) % kMod;
            }
        }
        return res;
    }
};

Matrix quickPow(Matrix x, int64_t p) {
    Matrix res;
    res.init(1);
    x = x * res;
    while (p) {
        if (p & 1) res = res * x;
        p >>= 1;
        x = x * x;
    }
    return res;
}

int main() {

    return 0;
}
