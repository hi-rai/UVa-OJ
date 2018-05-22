//A very easy problem

#include<bits/stdc++.h>
using namespace std;

int b, n, m, a[1010], d[20], ind, x[20];
string s, t;
void mod() {
    memset(x, 0, sizeof x);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 1; j--)
            x[j] = x[j - 1];
        x[0] = a[i];
        while (1) {
            int ind = m - 1, bor = 0;
            while (ind >= 0 && x[ind] == d[ind]) ind--;
            if (ind != -1 && x[ind] < d[ind]) break;
            for (int j = 0; j < m; j++) {
                if (x[j] - bor - d[j] >= 0) x[j] -= (bor + d[j]), bor = 0;
                else {
                    x[j] = b + x[j] - bor - d[j];
                    bor = 1;
                }
            }
        }
    }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> b, b) {
        cin >> s >> t;
        n = s.length();
        memset(a, 0, sizeof a);
        memset(d, 0, sizeof d);
        for (int i = 0; i < n; i++)
            a[i] = (int) (s[n - 1 - i] - '0');
        m = t.length();
        for (int i = 0; i < m; i++)
            d[i] = (int) (t[m - 1 - i] - '0');
        n += 5, m += 5;
        mod();
        ind = m - 1;
        while (ind >= 0 && x[ind] == 0) ind--;
        if (ind == -1) cout << 0;
        else while (ind >= 0) cout << x[ind--];
        cout << endl;
    }
    return 0;
}
