/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 带权并查集
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr int kMod = 1e9 + 7;

struct DSU {
    struct Node { int pre, value; };

    Node node[kMaxN];

    void init() {
        for (int i = 0; i < kMaxN; ++i) {
            node[i].pre = i;
            node[i].value = 0;
        }
    }

    int find(int x) {
        int pre = node[x].pre;
        if (pre != x) {
            node[x].pre = find(pre);
            node[x].value = (node[x].value + node[pre].value) % kMod;
        }
        return node[x].pre;
    }

    bool unionXToY(int x, int y, int v) {
        int xRoot = find(x), yRoot = find(y);
        if (xRoot != yRoot) {
            node[xRoot].pre = yRoot;
            node[xRoot].value = (-node[x].value + v + node[y].value + kMod) % kMod;
        } else if ((node[x].value - node[y].value + kMod) % kMod != v) {
            return false;
        }
        return true;
    }
};

int main() {

    return 0;
}
