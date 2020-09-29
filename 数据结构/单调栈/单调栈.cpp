/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 单调栈
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;

template<class T>
struct MStack {
    stack<T> s;

    void clear() { while (!s.empty()) s.pop(); }

    size_t size() { return s.size(); }

    bool empty() { return s.empty(); }

    void push(const T& data) {
        while (!s.empty() && data < s.top()) s.pop();
        s.push(data);
    }

    void pop() { return s.pop(); }

    T top() { return s.top(); }
};

int main() {

    return 0;
}
