//An easy problem.

#include<bits/stdc++.h>
using namespace std;

const int SZ = 505;
struct bigInt {
    int v[SZ], sign;
    bigInt() { memset(v, 0, sizeof v); sign = 1;}
    bigInt &operator= (const bigInt &a) {
        sign = a.sign;
        for (int i = 0; i < SZ; i++)
            v[i] = a.v[i];
        return (*this);
    }
    bigInt& operator* (long long a);
    bigInt& operator*= (long long a);
    bigInt& operator*= (const bigInt& a);
    bigInt& operator+= (const bigInt& a);
}c;

bigInt& bigInt::operator*= (long long a) {
    long long carry = 0, ch = 0;
    sign = sign * (a > 0 ? 1 : -1), a = abs(a);
    for (int i = 0; i < SZ; i++) {
        v[i] *= a, v[i] += carry;
        carry = v[i] / 10, v[i] %= 10;
        if(v[i]) ch = 1;
    }
    if(!ch) sign = 1;
    return (*this);
}

bigInt& bigInt::operator* (long long a) {
    long long carry = 0, ch = 0;
    c.sign = sign * (a > 0 ? 1 : -1), a = abs(a);
    for (int i = 0; i < SZ; i++) {
        c.v[i] = a * v[i] + carry;
        carry = c.v[i] / 10, c.v[i] %= 10;
        if(c.v[i])  ch = 1;
    }
    if(!ch) c.sign = 1;
    return c;
}

bigInt& bigInt::operator+= (const bigInt &a) {
    int add, carry = 0, ch, ind;
    if (a.sign == sign) add = 1;
    else {
        add = 0, ch = 1, ind = SZ - 1;
        while (v[ind] == a.v[ind] && ind >= 0) ind--;
        if (ind == -1) {
            sign = 1;
            memset(v, 0, sizeof v);
            return (*this);
        }
        if (v[ind] < a.v[ind]) sign *= -1, ch = -1;
    }
    if (add) {
        for (int i = 0; i < SZ; i++)
            v[i] = a.v[i] + v[i] + carry, carry = v[i] / 10, v[i] %= 10;
    } else {
        bitset<SZ + 5> bor = 0;
        if (ch == 1) {
            for (int i = 0; i < SZ; i++) {
                if (v[i] - bor[i] >= a.v[i]) {
                    v[i] = v[i] - a.v[i] - bor[i];
                } else {
                    bor[i + 1] = true;
                    v[i] = 10 + v[i] - a.v[i] - bor[i];
                }
            }
        } else {
            for (int i = 0; i < SZ; i++) {
                if (a.v[i] - bor[i] >= v[i]) {
                    v[i] = a.v[i] - v[i] - bor[i];
                } else {
                    bor[i + 1] = true;
                    v[i] = 10 + a.v[i] - v[i] - bor[i];
                }
            }
        }
    }
    return (*this);
}

bigInt& bigInt::operator*= (const bigInt& a) {
    bigInt d;
    int s = sign;
    sign = 1;
    for(int i = SZ - 1; i >= 0 ; i--) {
        d *= 10;
        d += (*this) * a.v[i];
    }
    d.sign = s * a.sign;
    sign = s;
    (*this) = d;
    return (*this);
}

ostream& operator<< (ostream& os, bigInt& a) {
    int x = SZ - 1;
    if (a.sign < 0) cout << "-";
    while (x >=0 && a.v[x] == 0) x--;
    if(x == -1)  cout << 0;
    else while (x >= 0) cout << a.v[x--];
    return cout;
}

istream& operator>> (istream& is, bigInt& a) {
    string s;
    cin >> s;
    int n = s.length();
    memset(a.v,0,sizeof a.v);
    if(s[0] == '-')   a.sign = -1, n--;
    else a.sign = 1;
    for (int i = s.length() - 1, j = 0; j < n; i--, j++)
        a.v[j] = (int) (s[i] - '0');
    return cin;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    bigInt a, b;
    while (cin >> a >> b)
        cout << (a *= b) << endl;
    return 0;
}
