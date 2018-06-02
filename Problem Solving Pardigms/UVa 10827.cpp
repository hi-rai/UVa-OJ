#include<bits/stdc++.h>
#define SZ 155
using namespace std;

int arr[SZ][SZ], TC, n, t;

int MaxSum2D() {
    int ans = INT_MIN, temp[SZ][SZ];
    memset(temp, 0, sizeof temp);
    for(int i = 1; i < 2 * n; i++)
        for(int j = 1; j < 2 * n; j++)
            temp[i][j] = temp[i - 1][j] + arr[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = i; j < i + n; j++) {
            int sum = 0, len = 0;
            for(int k = 1; k < 2 * n; k++) {
                if(len == n) { len = sum = 0, k -= n; continue; }
                sum += (temp[j][k] - temp[i - 1][k]), len++;
                ans = max(ans, sum);
                if(sum <= 0) {
                    len = 0, sum = 0;
                    if(k > n)   break;
                }
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
    cin >> TC;
    while(TC--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> t, arr[i][j] = arr[n + i][j] = arr[i][n + j] = arr[n + i][n + j] = t;
        cout << MaxSum2D() << endl;
    }
    return 0;
}
