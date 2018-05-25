#include<bits/stdc++.h>
using namespace std;

long long gcd(int x, long long y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    long long x, y, tc = 1;
    char str[20];
    while (scanf("%lld 0.%s", &x, str) == 2) {
        sscanf(str, "%lld", &y);
        if (x == 0) {
            long long d = strlen(str), e = 1;
            while (d--) e *= 10;
            long long g = gcd(max(e, y), min(e, y));
            cout << "Case " << tc++ << ": " << y / g << "/" << e / g << endl;
            continue;
        }
        long long z = y, t = x, d = strlen(str), e = 1, f = 1;
        while (t--) z /= 10;
        x = d - x;
        while (x--) e *= 10;
        while (d--) f *= 10;
        long long N = y - z, D = f - e, g = gcd(max(N, D), min(N, D));
        cout << "Case " << tc++ << ": " << N / g << "/" << D / g << endl;
    }
    return 0;
}
