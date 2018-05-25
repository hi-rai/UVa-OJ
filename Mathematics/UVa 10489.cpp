#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC, N, B, k, p, t, ans;
    cin >> TC;
    while(TC--) {
        cin >> N >> B;
        ans = 0;
        while(B--) {
            cin >> k, p = 1;
            for(int i = 0; i < k; i++)
                cin >> t, p *= t, p %= N;
            ans += p; ans %= N;
        }
        cout << ans << endl;
    }
    return 0;
}
