#include<bits/stdc++.h>
#define SZ 105
#define INF 100000
using namespace std;

int arr[SZ][SZ], TC, s, b, t, u, v, w;

int MaxSum2D(int r, int c) {
    int ans = -INF, temp[SZ][SZ], sum = 0;
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
    cin >> TC;
    while(TC--) {
        cin >> s >> b;
        for(int i = 1; i <= s; i++)
            for(int j = 1; j <= s; j++)
                arr[i][j] = 1;
        for(int i = 0; i < b; i++) {
            cin >> t >> u >> v >> w;
            for(int j = t; j <= v; j++)
                for(int k = u; k <= w; k++)
                    arr[j][k] = -INF;
        }
        cout << max(0, MaxSum2D(s, s)) << endl;
    }
    return 0;
}
