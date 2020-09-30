/**
 * @birth: created by Acathe on 2020-09-30
 * @content: 子序列自动机
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = 1e5 + 5;
constexpr size_t kCharN = 26;

struct SSAM {
    int first[kCharN];
    int nex[kMaxN][kCharN];

    int id(char c) { return c - 'a'; }

    void init(const string& s) {
        memset(first, -1, sizeof(first));
        memset(nex, -1, sizeof(nex));
        first[id(s[s.size() - 1])] = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            first[id(s[i])] = i;
            for (int j = 0; j < kCharN; j++) {
                if (id(s[i + 1]) != j) nex[i][j] = nex[i + 1][j];
                else nex[i][j] = i + 1;
            }
        }
    }

    bool match(const string& s) {
        int p = 0;
        for (int i = first[id(s[p])]; i != -1; i = nex[i][id(s[p])]) {
            p++;
            if (!s[p]) return true;
        }
        return false;
    }
};

int main() {

    return 0;
}
