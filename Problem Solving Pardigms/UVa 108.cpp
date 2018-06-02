#include<bits/stdc++.h>
#define SZ 105
using namespace std;

int arr[SZ][SZ], n;

int MaxSum2D(int r, int c) {
    int ans = INT_MIN, temp[SZ][SZ], sum = 0;
    memset(temp, 0, sizeof temp);
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            temp[i][j] = temp[i - 1][j] + arr[i][j];
    for(int i = 1; i <= r; i++)
        for(int j = i; j <= r; j++) {
            sum = 0;
            for(int k = 1; k <= c; k++) {
                sum += (temp[j][k] - temp[i - 1][k]);
                ans = max(ans, sum);
                sum = max(0, sum);
            }
        }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for(int  i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];
    cout << MaxSum2D(n, n) << endl;
    return 0;
}
