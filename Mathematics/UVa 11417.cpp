#include<bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int val[505][505], n;
    for (int i = 1; i < 505; i++)
        for (int j = i + 1; j < 505; j++)
            val[i][j] = gcd(i, j);
    while (cin >> n, n) {
        long long ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                ans += val[i][j];
        cout << ans << endl;
    }
    return 0;
}
