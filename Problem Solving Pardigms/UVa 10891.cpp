//A very good DP problem. Though it appears that a greedy algorithm might work, it fails as is clear from the first example test case
//in the problem statement.

#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;

int arr[105], memo[105][105], n, d[105][105];

int calc(int l, int r) {
    if (l > r) return 0;
    if (d[l][r]) return memo[l][r];
    d[l][r] = 1;
    int temp = -INF;
    for (int i = l, s = 0; i <= r; i++)
        s += arr[i], temp = max(temp, s - calc(i + 1, r));
    for (int i = r, s = 0; i >= l; i--)
        s += arr[i], temp = max(temp, s - calc(l, i - 1));
    return memo[l][r] = temp;
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
            cin >> arr[i];
        memset(d, 0, sizeof d);
        cout << calc(0, n - 1) << endl;
    }
    return 0;
}
