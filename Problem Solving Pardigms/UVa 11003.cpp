#include<bits/stdc++.h>
using namespace std;

int n, w[1005], a[1005], memo[1005][6005];

int calc(int b, int t) {
    if (b >= n || t <= 0) return 0;
    if (memo[b][t] != -1) return memo[b][t];
    memo[b][t] = calc(b + 1, t);
    if (t >= w[b]) memo[b][t] = max(memo[b][t], calc(b + 1, min(a[b], t - w[b])) + 1);
    return memo[b][t];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> n, n) {
        for (int i = 0; i < n; i++)
            cin >> w[i] >> a[i];
        memset(memo, -1, sizeof memo);
        cout << calc(0, 6000) << endl;
    }
    return 0;
}
