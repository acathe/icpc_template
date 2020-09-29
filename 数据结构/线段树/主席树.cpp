/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 主席树
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include<bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr size_t kLogN = 25;

struct PersistTree {
    int root[kMaxN];
    int node[kMaxN * kLogN], cnt;
    int lSon[kMaxN * kLogN], rSon[kMaxN * kLogN];

    void init(int l, int r) {
        cnt = 0;
        build(l, r, root[0]);
    }

    void pushUp(int rt) {
        node[rt] = node[lSon[rt]] + node[rSon[rt]];
    }

    void build(int l, int r, int& rt) {
        rt = ++cnt;
        node[rt] = 0;
        if (l == r) return;
        int m = (l + r) >> 1;
        build(l, m, lSon[rt]);
        build(m + 1, r, rSon[rt]);
    }

    void update(int k, int v, int l, int r, int pre, int& rt) {
        rt = ++cnt;
        lSon[rt] = lSon[pre];
        rSon[rt] = rSon[pre];
        if (l == r) {
            node[rt] = node[pre] + v;
            return;
        }
        int m = (l + r) >> 1;
        if (k <= m) update(k, v, l, m, lSon[pre], lSon[rt]);
        else update(k, v, m + 1, r, rSon[pre], rSon[rt]);
        pushUp(rt);
    }

    int query(int k, int l, int r, int pre, int rt) {
        if (l == r) return l;
        int m = (l + r) >> 1;
        int sum = node[lSon[rt]] - node[lSon[pre]];
        if (k <= sum) return query(k, l, m, lSon[pre], lSon[rt]);
        else return query(k - sum, m + 1, r, rSon[pre], rSon[rt]);
    }
};

int main() {

    return 0;
}
