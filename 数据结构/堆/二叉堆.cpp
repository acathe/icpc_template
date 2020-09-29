/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 二叉堆
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

template<class T>
struct Heap {
    vector<T> data;

    void make(T* first, T* last) {
        data.clear();
        while (first != last) {
            data.push_back(*first);
            ++first;
        }
        make_heap(data.begin(), data.end());
    }

    void clear() { data.clear(); }

    size_t size() { return data.size(); }

    bool empty() { return data.empty(); }

    void push(const T& x) {
        data.push_back(x);
        push_heap(data.begin(), data.end());
    }

    void pop() {
        pop_heap(data.begin(), data.end());
        data.pop_back();
    }

    T top() { return data.front(); }
};

int main() {

    return 0;
}
