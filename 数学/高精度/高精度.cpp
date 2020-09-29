/**
 * @birth: created by Acathe on 2020-09-29
 * @content: 高精度
 * @version 1.0.0
 * @revision: last revised by Acathe on 2020-09-29
*/

#include <bits/stdc++.h>

using namespace std;


struct BigInt {
    static constexpr int kBase = 100000000;
    static constexpr int kWidth = 8;

    bool sign;
    size_t length;
    vector<int> num;

    BigInt(int64_t x = 0) { *this = x; }

    BigInt(const string& x) { *this = x; }

    BigInt(const BigInt& x) { *this = x; }

    void cutLeadingZero() {
        while (num.back() == 0 && num.size() != 1) num.pop_back();
        int tmp = num.back();
        if (tmp == 0) {
            length = 1;
        } else {
            length = (num.size() - 1) * kWidth;
            while (tmp > 0) {
                ++length;
                tmp /= 10;
            }
        }
    }

    BigInt& operator=(int64_t x) {
        num.clear();
        if (x >= 0) {
            sign = true;
        } else {
            sign = false;
            x = -x;
        }
        do {
            num.push_back(x % kBase);
            x /= kBase;
        } while (x > 0);
        cutLeadingZero();
        return *this;
    }

    BigInt& operator=(const string& str) {
        num.clear();
        sign = (str[0] != '-');
        int x, len = (str.size() - 1 - (!sign)) / kWidth + 1;
        for (int i = 0; i < len; ++i) {
            int End = str.size() - i * kWidth;
            int start = max((int)(!sign), End - kWidth);
            sscanf(str.substr(start, End - start).c_str(), "%d", &x);
            num.push_back(x);
        }
        cutLeadingZero();
        return *this;
    }

    BigInt& operator=(const BigInt& tmp) {
        num = tmp.num;
        sign = tmp.sign;
        length = tmp.length;
        return *this;
    }

    BigInt abs() const {
        BigInt ans(*this);
        ans.sign = true;
        return ans;
    }

    const BigInt& operator+() const { return *this; }

    BigInt operator-() const {
        BigInt ans(*this);
        if (ans != 0) ans.sign = !ans.sign;
        return ans;
    }

    BigInt operator+(const BigInt& b) const {
        if (!b.sign) return *this - (-b);
        if (!sign) return b - (-*this);
        BigInt ans;
        ans.num.clear();
        for (int i = 0, g = 0; ; ++i) {
            if (g == 0 && i >= num.size() && i >= b.num.size()) break;
            int x = g;
            if (i < num.size()) x += num[i];
            if (i < b.num.size()) x += b.num[i];
            ans.num.push_back(x % kBase);
            g = x / kBase;
        }
        ans.cutLeadingZero();
        return ans;
    }

    BigInt operator-(const BigInt& b) const {
        if (!b.sign) return *this + (-b);
        if (!sign) return -((-*this) + b);
        if (*this < b) return -(b - *this);
        BigInt ans;
        ans.num.clear();
        for (int i = 0, g = 0;; ++i) {
            if (g == 0 && i >= num.size() && i >= b.num.size()) break;
            int x = g;
            g = 0;
            if (i < num.size()) x += num[i];
            if (i < b.num.size()) x -= b.num[i];
            if (x < 0) {
                x += kBase;
                g = -1;
            }
            ans.num.push_back(x);
        }
        ans.cutLeadingZero();
        return ans;
    }

    BigInt operator*(const BigInt& b) const {
        int lena = num.size(), lenb = b.num.size();
        BigInt ans;
        for (int i = 0; i < lena + lenb; ++i)
            ans.num.push_back(0);
        for (int i = 0, g = 0; i < lena; ++i) {
            g = 0;
            for (int j = 0; j < lenb; ++j) {
                int64_t x = ans.num[i + j];
                x += (int64_t)num[i] * (int64_t)b.num[j];
                ans.num[i + j] = x % kBase;
                g = x / kBase;
                ans.num[i + j + 1] += g;
            }
        }
        ans.cutLeadingZero();
        ans.sign = (ans.length == 1 && ans.num[0] == 0) || (sign == b.sign);
        return ans;
    }

    BigInt e(size_t n) const {
        int tmp = n % kWidth;
        BigInt ans;
        ans.length = n + 1;
        n /= kWidth;
        while (ans.num.size() <= n) ans.num.push_back(0);
        ans.num[n] = 1;
        while (tmp--) ans.num[n] *= 10;
        return ans * (*this);
    }

    BigInt operator/(const BigInt& b) const {
        BigInt aa((*this).abs());
        BigInt bb(b.abs());
        if (aa < bb) return 0;
        char *str = new char[aa.length + 1];
        memset(str, 0, sizeof(char) * (aa.length + 1));
        BigInt tmp;
        int lena = aa.length, lenb = bb.length;
        for (int i = 0; i <= lena - lenb; ++i) {
            tmp = bb.e(lena - lenb - i);
            while (aa >= tmp) {
                str[i]++;
                aa = aa - tmp;
            }
            str[i] += '0';
        }
        BigInt ans(str);
        delete[] str;
        ans.sign = (ans == 0 || sign == b.sign);
        return ans;
    }

    BigInt operator%(const BigInt& b) const {
        return *this - *this / b * b;
    }

    BigInt& operator++() { return *this = *this + 1; }

    BigInt& operator--() { return *this = *this - 1; }

    BigInt& operator+=(const BigInt& b) { return *this = *this + b; }

    BigInt& operator-=(const BigInt& b) { return *this = *this - b; }

    BigInt& operator*=(const BigInt& b) { return *this = *this * b; }

    BigInt& operator/=(const BigInt& b) { return *this = *this / b; }

    BigInt& operator%=(const BigInt& b) { return *this = *this % b; }

    bool operator<(const BigInt& b) const {
        if (sign != b.sign) return !sign;
        else if (!sign && !b.sign) return -b < -*this;
        if (num.size() != b.num.size()) return num.size() < b.num.size();
        for (int i = num.size() - 1; i >= 0; i--)
            if (num[i] != b.num[i]) return num[i] < b.num[i];
        return false;
    }

    bool operator>(const BigInt& b) const { return b < *this; }

    bool operator<=(const BigInt& b) const { return !(b < *this); }

    bool operator>=(const BigInt& b) const { return !(*this < b); }
    
    bool operator!=(const BigInt& b) const { return b < *this || *this < b; }

    bool operator==(const BigInt& b) const { return !(b < *this) && !(*this < b); }

    bool operator||(const BigInt& b) const { return *this != 0 || b != 0; }

    bool operator&&(const BigInt& b) const { return *this != 0 && b != 0; }

    bool operator!() { return *this == 0; }

    friend ostream& operator<<(ostream& out, const BigInt& x) {
        if (!x.sign) out << '-';
        out << x.num.back();
        for (int i = x.num.size() - 2; i >= 0; i--) {
            char buf[10];
            sprintf(buf, "%08d", x.num[i]);
            for (int j = 0; j < strlen(buf); ++j)
                out << buf[j];
        }
        return out;
    }

    friend istream& operator>>(istream& in, BigInt& x) {
        string str;
        in >> str;
        size_t len = str.size();
        int start = 0;
        if (str[0] == '-') start = 1;
        if (str[start] == '\0') return in;
        for (int i = start; i < len; ++i)
            if (str[i] < '0' || str[i] > '9') return in;
        x.sign = !start;
        x = str.c_str();
        return in;
    }
};

int main() {

    return 0;
}
