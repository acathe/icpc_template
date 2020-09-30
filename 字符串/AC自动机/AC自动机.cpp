/**
 * @birth: created by Acathe on 2020-09-30
 * @content: AC自动机
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e6 + 5;
constexpr size_t kCharN = 26;

struct ACAM {
    struct Node { int nex[kCharN], fail, last; };

    Node node[kMaxN];
    int cnt, root;

    int id(char c) { return c - 'a'; }

    void init() {
        root = cnt = 0;
        memset(node, 0, sizeof(node));
    }

    void insert(const string& s) {
        int p = root;
        for (int i = 0; s[i]; i++) {
            if (!node[p].nex[id(s[i])]) node[p].nex[id(s[i])] = ++cnt;
            p = node[p].nex[id(s[i])];
        }
        node[p].last++;
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < kCharN; i++)
            if (node[root].nex[i]) q.push(node[root].nex[i]);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < kCharN; i++) {
                if (node[now].nex[i]) {
                    node[node[now].nex[i]].fail = node[node[now].fail].nex[i];
                    q.push(node[now].nex[i]);
                } else {
                    node[now].nex[i] = node[node[now].fail].nex[i];
                }
            }
        }
    }

    int match(const string& s) {
        int p = root, res = 0;
        for (int i = 0; s[i]; i++) {
            p = node[p].nex[id(s[i])];
            for (int j = p; j != root && node[j].last != -1; j = node[j].fail) {
                res += node[j].last;
                node[j].last = -1;
            }
        }
        return res;
    }

    void clear() {
        for (int i = 0; i <= cnt; i++) {
            memset(node[i].nex, 0, sizeof(node[i].nex));
            node[i].last = node[i].fail = 0;
        }
        cnt = 0;
    }
};

int main() {

    return 0;
}
