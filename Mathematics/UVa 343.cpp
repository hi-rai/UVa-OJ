//An easy brute force problem. Though the max size possible is not mentioned using long long will suffice

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string x, y;
    int a, c, b, check, m, n;
    while (cin >> x >> y) {
        check = 0, m = x.length(), n = y.length(), a = 1, c = 1;
        for (int i = 0; i < m; i++) {
            if (x[i] <= '9' && x[i] >= '0') a = max(a, (int) (x[i] - '0'));
            else a = max(a, (int) (x[i] - 'A') + 10);
        }
        for (int i = 0; i < n; i++) {
            if (y[i] <= '9' && y[i] >= '0') c = max(c, (int) (y[i] - '0'));
            else c = max(c, (int) (y[i] - 'A') + 10);
        }
        a++, c++;
        for (; a < 37 && !check; a++)
            for (b = c; b < 37 && !check; b++) {
                long long e = 0, f = 0, p = 1, q = 1;
                for (int i = m - 1; i >= 0; i--) {
                    if (x[i] <= '9' && x[i] >= '0') e += p * (int) (x[i] - '0');
                    else e += p * ((int) (x[i] - 'A') + 10);
                    p *= a;
                }
                for (int i = n - 1; i >= 0; i--) {
                    if (y[i] <= '9' && y[i] >= '0') f += q * (int) (y[i] - '0');
                    else f += q * ((int) (y[i] - 'A') + 10);
                    q *= b;
                }
                if (e == f) {
                    check = 1;
                    break;
                }
            }
        if (a == 37 && b == 37) cout << x << " is not equal to " << y << " in any base 2..36\n";
        else cout << x << " (base " << a - 1 << ") = " << y << " (base " << b << ")\n";
    }
    return 0;
}
