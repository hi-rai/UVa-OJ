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
    int n, a[33000];
    while (cin >> n, n) {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                cnt += (gcd(max(a[i], a[j]), min(a[i], a[j])) == 1);
        if (cnt == 0) cout << "No estimate for this data set.\n";
        else {
            double ans = sqrt(3 * n * (double)(n - 1) / (double)cnt);
            cout << fixed << setprecision(6) << ans << endl;
        }
    }
    return 0;
}
