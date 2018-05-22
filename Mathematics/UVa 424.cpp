An easy problem

#include<bits/stdc++.h>
using namespace std;

const int SZ = 105;
struct bigInt {
    int v[SZ];
    bigInt() { memset(v, 0, sizeof v); }
    bigInt &operator+=(const bigInt &a);
};

bigInt& bigInt::operator+= (const bigInt &a) {
    int carry = 0;
    for (int i = 0; i < SZ; i++)
        v[i] = a.v[i] + v[i] + carry, carry = v[i] / 10, v[i] %= 10;
    return (*this);
}

ostream& operator<< (ostream& os, bigInt& a) {
    int x = SZ - 1;
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
    for (int i = s.length() - 1, j = 0; j < n; i--, j++)
        a.v[j] = (int) (s[i] - '0');
    return cin;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    bigInt a, b;
    while (cin >> a) b += a;
    cout << b << endl;
    return 0;
}
