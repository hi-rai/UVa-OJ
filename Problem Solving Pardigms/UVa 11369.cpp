#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC, n, a[20005], ans;
    cin >> TC;
    while(TC--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n), ans = 0;
        for(int i = n - 3; i >= 0; i -= 3)
            ans += a[i];
        cout << ans << endl;
    }
    return 0;
}
