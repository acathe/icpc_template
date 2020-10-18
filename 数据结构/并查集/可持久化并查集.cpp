/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 可持久化并查集
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr size_t kLogN = 25;

struct PersistTree {
    struct Node { int pre, dep, lSon, rSon; };

    int cnt;
    Node node[kMaxN * kLogN];
    int root[kMaxN];

    void init() { cnt = 0; }

    void build(int l, int r, int &rt) {
        rt = ++cnt;
        if (l == r) {
            node[rt].pre = l;
            node[rt].dep = 1;
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, node[rt].lSon);
        build(m + 1, r, node[rt].rSon);
    }

    void update(int k, int v, int l, int r, int last, int &rt) {
        rt = ++cnt;
        node[rt] = node[last];
        if (l == r) {
            node[rt].pre = v;
            return;
        }
        int m = (l + r) >> 1;
        if (k <= m) update(k, v, l, m, node[last].lSon, node[rt].lSon);
        else update(k, v, m + 1, r, node[last].rSon, node[rt].rSon);
    }

    int query(int k, int l, int r, int rt) {
        if (l == r) return rt;
        int m = (l + r) >> 1;
        if (k <= m) return query(k, l, m, node[rt].lSon);
        else return query(k, m + 1, r, node[rt].rSon);
    }
};

struct PersistDSU {
    int n, cnt;
    PersistTree tree;

    void init(int n) {
        this->n = n;
        cnt = 0;
        tree.init();
        tree.build(1, n, tree.root[cnt]);
    }

    void update(int k, int l, int r, int rt) {
        if (l == r) {
            ++tree.node[rt].dep;
            return;
        }
        int m = (l + r) >> 1;
        if (k <= m) update(k, l, m, tree.node[rt].lSon);
        else update(k, m + 1, r, tree.node[rt].rSon);
    }

    int find(int x, int tim) {
        int rt = tree.query(x, 1, n, tree.root[tim]);
        if (x == tree.node[rt].pre) return rt;
        return find(tree.node[rt].pre, tim);
    }

    int unionXToYInTim(int x, int y, int tim) {
        int xRoot = find(x, tim), yRoot = find(y, tim);
        if (tree.node[xRoot].pre == tree.node[yRoot].pre) return tim;
        if (tree.node[xRoot].dep > tree.node[yRoot].dep) swap(xRoot, yRoot);
        tree.update(tree.node[xRoot].pre, tree.node[yRoot].pre, 1, n, tree.root[tim], tree.root[++cnt]);
        if (tree.node[xRoot].dep == tree.node[yRoot].dep)
            update(tree.node[yRoot].pre, 1, n, tree.root[cnt]);
        return cnt;
    }
};

int main() {

    return 0;
}
