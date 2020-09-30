/**
 * @birth: created by Acathe on 2020-09-30
 * @content: Manacher
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;

int p[kMaxN << 1];

int manacher(const string& t) {
    string s((t.size() << 1) + 2, '#');
    int n = s.size();
    for (int i = 2; i < n; i += 2)
        s[i] = t[(i >> 1) - 1];
    int mid, r = 0;
    for (int i = 1; i < n; i++) {
        p[i] = i < r ? min(p[(mid << 1) - i], r - i) : 1;
        while (s[i - p[i]] == s[i + p[i]]) p[i]++;
        if (r < i + p[i]) {
            mid = i;
            r = i + p[i];
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++)
        res = max(res, p[i] - 1);
    return res;
}

int main() {

    return 0;
}
