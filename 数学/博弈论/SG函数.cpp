/**
 * @birth: created by Acathe on 2020-09-29
 * @content: SG函数
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1005;

int n;
int sg[kMaxN];
bool s[kMaxN];

int mex(bool* s) {
    int i = 0;
    while (s[i]) ++i;
    return i;
}

void table() {
    sg[0] = 0;
    for (int i = 1; i < kMaxN; ++i) {
        memset(s, 0, sizeof(s));
        for (int j = 1; j <= i; ++j)
            s[sg[i - j]] = true;
        sg[i] = mex(s);
    }
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif // DEBUG
    table();
    cin >> n;
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        flag ^= sg[a];
    }
    cout << (flag ? "Alice\n" : "Bob\n");
    return 0;
}
