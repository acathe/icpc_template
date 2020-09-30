/**
 * @birth: created by Acathe on 2020-09-30
 * @content: SA
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxN = (1e5 + 5) * 2;

struct Map {
    int data[kMaxN], cnt;

    void init() { cnt = 0; }

    void push(int v) { data[cnt++] = v; }

    void solve() {
        sort(data, data + cnt);
        cnt = unique(data, data + cnt) - data;
    }

    int rank(int k) { return data[k - 1]; }

    int find(int v) { return lower_bound(data, data + cnt, v) - data + 1; }
};

struct SA {
    int n;
    Map mapp;
    int a[kMaxN];
    int sa[kMaxN], rk[kMaxN];
    int ht[kMaxN];
    pair<int, int> key[kMaxN];
    int tmp[kMaxN], buc[kMaxN];

    void radixSort() {
        memset(buc, 0, sizeof(buc));
        for (int i = 1; i <= n; i++)
            buc[key[i].second]++;
        for (int i = 1; i <= n; i++)
            buc[i] += buc[i - 1];
        for (int i = 1; i <= n; i++)
            tmp[n - --buc[key[i].second]] = i;
        memset(buc, 0, sizeof(buc));
        for (int i = 1; i <= n; i++)
            buc[key[i].first]++;
        for (int i = 1; i <= n; i++)
            buc[i] += buc[i - 1];
        for (int i = 1; i <= n; i++)
            sa[buc[key[tmp[i]].first]--] = tmp[i];
    }

    void init(const string& s) {
        n = s.size();
        mapp.init();
        for (int i = 0; i < n; i++)
            mapp.push(s[i]);
        mapp.solve();
        for (int i = 1; i <= n; i++)
            a[i] = mapp.find(s[i - 1]);
        memset(buc, 0, sizeof(buc));
        for (int i = 1; i <= n; i++)
            buc[a[i]]++;
        for (int i = 1; i <= n; i++)
            buc[i] += buc[i - 1];
        for (int i = 1; i <= n; i++)
            rk[i] = buc[a[i] - 1] + 1;
        for (int l = 1; l <= n; l <<= 1) {
            for (int i = 1; i <= n; i++) {
                key[i].first = rk[i];
                key[i].second = i + l > n ? 0 : rk[i + l];
            }
            radixSort();
            for (int i = 1; i <= n; i++)
                rk[sa[i]] = rk[sa[i - 1]] + (key[sa[i]] != key[sa[i - 1]]);
        }
        int lcp = 0;
        for (int i = 1; i <= n; i++) {
            if (lcp > 0) lcp--;
            int j = sa[rk[i] - 1];
            while (i + lcp <= n && j + lcp <= n && a[i + lcp] == a[j + lcp])
                lcp++;
            ht[rk[i]] = lcp;
        }
    }
};

int main() {

    return 0;
}
