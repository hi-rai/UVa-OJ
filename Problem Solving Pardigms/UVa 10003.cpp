#include<bits/stdc++.h>
using namespace std;

int arr[55], n, l, memo[55][55];

int calc(int l, int r) {
    if(r == l + 1) return 0;
    if(memo[l][r] != -1) return memo[l][r];
    int ans = INT_MAX;
    for(int i = l + 1; i < r; i++)
        ans = min(calc(l, i) + calc(i, r), ans);
    return memo[l][r] = ans + arr[r] - arr[l];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> l >> n, l) {
        memset(memo, -1, sizeof memo);
        arr[0] = 0, arr[n + 1] = l;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        cout << "The minimum cutting is " << calc(0, n + 1) << "." << endl;
    }
    return 0;
}
