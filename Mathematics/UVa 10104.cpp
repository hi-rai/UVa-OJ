//Calculate the solution of the diophantine equation. There would be four case to conider to minimize the value of |x| + |y|

#include<bits/stdc++.h>
using namespace std;

long long a, b, x, y, gcd, swapped, ans, t;

void extendedEuclid(long long a, long long b) {
    if (b == 0) { x = 1, y = 0, gcd = a; return; }
    extendedEuclid(b, a % b);
    swap(x, y);
    y = y - a / b * x;
}

long long calc(long long t) {
    return abs(x + b / gcd * t) + abs(y - a / gcd * t);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> a >> b) {
        if (a < b) swap(a, b), swapped = 1;
        else swapped = 0;
        extendedEuclid(a, b);
        auto p = (int)floor(-x * gcd / (double)b), q =(int)ceil(-x * gcd / (double)b);
        auto r = (int)floor(y * gcd / (double)a), s =(int)ceil(y * gcd / (double)a);
        ans = p, t = calc(p);
        if(calc(q) < t)   ans = q, t = calc(q);
        if(calc(r) < t)   ans = r, t = calc(r);
        if(calc(s) < t)   ans = s;
        if(swapped) cout << y - a / gcd * ans << " " << x + b / gcd * ans << " " << gcd << endl;
        else cout << x + b / gcd * ans << " " << y - a / gcd * ans << " " << gcd << endl;
    }
    return 0;
}
