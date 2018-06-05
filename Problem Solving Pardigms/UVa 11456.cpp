#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC, n, arr[2005], incr[2005], decr[2005], ans;
    cin >> TC;
    while (TC--) {
        cin >> n;
        if(n == 0) {
            cout << 0 << endl;
            continue;
        }
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        incr[n - 1] = 1, decr[n - 1] = 1, ans = 1;
        for(int i = n - 2; i >= 0; i--) {
            incr[i] = 0, decr[i] = 0;
            for(int j = i + 1; j < n; j++) {
                if(arr[j] > arr[i]) incr[i] = max(incr[i], incr[j]);
                else decr[i] = max(decr[i], decr[j]);
            }
            incr[i]++, decr[i]++;
            ans = max(ans, incr[i] + decr[i] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
