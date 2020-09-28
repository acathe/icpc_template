/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 素性测试
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include<bits/stdc++.h>

using namespace std;

inline int64_t mul(int64_t x, int64_t y, int64_t MOD) {
    x %= MOD;
    y %= MOD;
    return (x * y - int64_t((long double)x * y / MOD) * MOD + MOD) % MOD;
}

int64_t quickPow(int64_t x, int64_t p, int64_t MOD) {
    int64_t res = 1;
    x %= MOD;
    while (p) {
        if (p & 1) res = mul(res, x, MOD);
        p >>= 1;
        x = mul(x, x, MOD);
    }
    return res % MOD;
}

bool millerRabbin(int64_t x, int64_t p) {
    if (quickPow(x, p - 1, p) != 1) return false;
    for (int64_t i = p - 1; !(i & 1); i >>= 1) {
        int64_t k = quickPow(x, i >> 1, p);
        if (k == p - 1) return true;
        else if (k != 1) return false;
    }
    return true;
}

bool isPrime(int64_t x) {
    if (x < 2) return false;
    int64_t prime[] =  {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (const auto& p: prime) {
        if (x == p) return true;
        else if (!millerRabbin(p, x)) return false;
    }
    return true;
}

int main() {

    return 0;
}
