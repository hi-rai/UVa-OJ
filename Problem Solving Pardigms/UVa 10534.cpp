#include<bits/stdc++.h>
#define SZ 10005
using namespace std;

int arr[SZ], revarr[SZ], inc[SZ], decr[SZ], n, ans;

int LIS(int arr[], int l[], int n) {
    int s[SZ], len = 1;
    s[0] = arr[0], l[0] = 1;
    for(int i = 1; i < n; i++) {
        int t = lower_bound(s, s + len, arr[i]) - s;
        if(t == len) s[len++] = arr[i];
        else if(arr[i] < s[t]) s[t] = arr[i];
        l[i] = t + 1;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> n) {
        for (int i = 0, j = n - 1; i < n; i++, j--)
            cin >> arr[i], revarr[j] = arr[i];
        LIS(arr, inc, n), LIS(revarr, decr, n), ans = 1;
        for (int i = 0; i < n; i++) {
            int t = inc[i], u = decr[n - i - 1];
            ans = max(ans, 2 * min(t, u) - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
