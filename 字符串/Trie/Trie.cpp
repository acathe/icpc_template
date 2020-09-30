/**
 * @birth: created by Acathe on 2020-09-30
 * @content: Trie
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr size_t kCharN = 26;

struct Trie {
    struct Node { int nex[kCharN], last; };

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
            if (!node[p].nex[id(s[i])])
                node[p].nex[id(s[i])] = ++cnt;
            p = node[p].nex[id(s[i])];
        }
        node[p].last++;
    }

    int match(const string& s) {
        int p = root;
        for (int i = 0; s[i]; i++) {
            if (!node[p].nex[id(s[i])]) return 0;
            p = node[p].nex[id(s[i])];
        }
        return node[p].last;
    }

    void clear() {
        for (int i = 0; i <= cnt; i++) {
            memset(node[i].nex, 0, sizeof(node[i].nex));
            node[i].last = 0;
        }
        cnt = 0;
    }
};

int main() {

    return 0;
}
