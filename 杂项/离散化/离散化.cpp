/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 离散化
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include<bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = (1e5 + 5) * 2;

struct Map {
    int data[kMaxN], cnt;

    void init() { cnt = 0; }

    void push(int v) { data[cnt++] = v; }

    void solve() {
        sort(data, data + cnt);
        cnt = unique(data, data + cnt) - data;
        for (int i = cnt - 1; i > 0; --i)
            if (data[i] - data[i - 1] > 1) data[cnt++] = data[i - 1] + 1;
        sort(data, data + cnt);
    }

    int rank(int k) { return data[k - 1]; }

    int find(int v) { return lower_bound(data, data + cnt, v) - data + 1; }
};

int main() {

    return 0;
}
