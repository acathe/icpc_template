/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 单调队列
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

template<class T>
struct MQueue {
    deque<T> q;

    void clear() { q.clear(); }

    size_t size() { return q.size(); }

    bool empty() { return q.empty(); }

    void push(const T& data) {
        while (!q.empty() && data < q.back()) q.pop_back();
        q.push_back(data);
    }

    void pop() { return q.pop_front(); }

    T front() { return q.front(); }
};

int main() {

    return 0;
}
