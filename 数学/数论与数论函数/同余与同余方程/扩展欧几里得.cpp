/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 扩展欧几里得
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

int64_t exGcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64_t r = exGcd(b, a % b, y, x);
    y -= a / b * x;
    return r;
}

int main() {

    return 0;
}
