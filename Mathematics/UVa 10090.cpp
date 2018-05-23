//extended euclid plus a bit of calculus will do the job

#include<bits/stdc++.h>
using namespace std;

long long n, c1, c2, n1, n2, x, y, gcd, swapped, l, h, t, p, q;

void extendedEuclid(long long a, long long b) {
    if (b == 0) { x = 1, y = 0, gcd = a; return; }
    extendedEuclid(b, a % b);
    swap(x, y);
    y = y - a / b * x;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin>>n,n) {
        cin >> c1 >> n1 >> c2 >> n2;
        if(n1 < n2) swap(c1, c2), swap(n1, n2), swapped = 1;
        else swapped = 0;
        extendedEuclid(n1, n2);
        if(n % gcd) cout << "failed\n";
        else {
            t = n / gcd, x *= t, y *= t;
            l = (int)ceil(-x * gcd / (double)n2), h = (int)floor(y * gcd / (double)n1);
            if(l > h) {
                cout << "failed\n";
                continue;
            }
            p = c1 * (x + n2 * l / gcd) + c2 * (y - n1 * l / gcd);
            q = c1 * (x + n2 * h / gcd) + c2 * (y - n1 * h / gcd);
            if(p < q) x = (x + n2 * l / gcd), y = (y - n1 * l / gcd);
            else x = (x + n2 * h / gcd), y = (y - n1 * h / gcd);
            if(swapped) cout << y << " " << x <<"\n";
            else cout << x << " " << y << "\n";
        }
    }
    return 0;
}
