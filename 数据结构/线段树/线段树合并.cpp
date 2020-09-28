/**
 * @birth: created by Acathe on 2020-09-28
 * @content: 线段树合并
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-28
*/

#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 5;
const int kLogN = 25;

struct SegmentTree {
    struct Node { int data; };

    Node node[kMaxN * kLogN];
    int lSon[kMaxN * kLogN], rSon[kMaxN * kLogN];
    int root[kMaxN], cnt;

    void init() {
        cnt = 0;
        node[0].data = 0;
        memset(root, 0, sizeof(root));
    }

    inline void newNode(int &rt) {
        rt = ++cnt;
        node[rt] = node[0];
        lSon[rt] = rSon[rt] = 0;
    }

    inline Node merge(const Node &lSon, const Node &rSon) {
        Node res;
        res.data = lSon.data + rSon.data;
        return res;
    }

    inline void pushUp(int rt) {
        node[rt] = merge(node[lSon[rt]], node[rSon[rt]]);
    }

    void upDate(int k, int v, int l, int r, int &rt) {
        if (!rt) newNode(rt);
        if (l == r) {
            node[rt].data += v;
            return;
        }
        int m = (l + r) >> 1;
        if (k <= m) upDate(k, v, l, m, lSon[rt]);
        else upDate(k, v, m + 1, r, rSon[rt]);
        pushUp(rt);
    }

    Node query(int L, int R, int l, int r, int rt) {
        if (!rt) return node[0];
        if (L <= l && r <= R) return node[rt];
        int m = (l + r) >> 1;
        if (R <= m) return query(L, R, l, m, lSon[rt]);
        else if (m < L) return query(L, R, m + 1, r, rSon[rt]);
        else return merge(query(L, R, l, m, lSon[rt]), query(L, R, m + 1, r, rSon[rt]));
    }

    void mergeTree(int l, int r, int pre, int &rt) {
        if (!rt || !pre) {
            rt = rt ? rt : pre;
            return;
        }
        if (l == r) {
            node[rt].data += node[pre].data;
            return;
        }
        int m = (l + r) >> 1;
        mergeTree(l, m, lSon[pre], lSon[rt]);
        mergeTree(m + 1, r, rSon[pre], rSon[rt]);
        pushUp(rt);
    }
};

int main() {

    return 0;
}
