/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 01分数规划
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr double kEps = 1e-8;

int n;
int a[kMaxN], b[kMaxN];

bool judge(double x) {
    double res = 0.0;
    for (int i = 1; i <= n; ++i) {
        if (1.0 * a[i] - x * b[i] > 0)
            res += 1.0 * a[i] - x * b[i];
    }
    return res > -kEps;
}

double solve() {
    double l = 0.0, r = 0.0;
    for (int i = 1; i <= n; ++i)
        r += 1.0 * a[i];
    while (r - l >= kEps) {
        double mid = l + (r - l) / 2.0;
        if (judge(mid)) l = mid + kEps;
        else r = mid;
    }
    return l;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    cout << round(solve()) << endl;
    return 0;
}
