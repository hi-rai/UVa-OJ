#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, ans;
    while (cin >> n >> k, !cin.eof) {
        ans = n;
        while (n >= k)
            ans += n / k, n = n / k + n % k;
        cout << ans << endl;
    }
    return 0;
}
