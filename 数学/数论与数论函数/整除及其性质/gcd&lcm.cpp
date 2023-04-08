/**
 * @birth: created by Acathe on 2020-09-29
 * @content: gcd&lcm
 * @version 1.0.1
 * @revision: last revised by Acathe on 2023-04-09
*/

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : abs(a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {

    return 0;
}
