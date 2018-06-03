#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC, memo[10][1005], arr[10][1005], n;
    cin >> TC;
    while (TC--) {
        cin >> n, n /= 100;
        for(int i = 9; i >= 0; i--)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j], memo[i][j] = INF;
        for(int i = 9; i >= 0; i--) memo[i][n] = INF;
        memo[0][0] = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= 9; j++) {
            if(j != 9) memo[j + 1][i + 1] = min(memo[j + 1][i + 1], memo[j][i] + 60 - arr[j][i]);
            if(j != 0) memo[j - 1][i + 1] = min(memo[j - 1][i + 1], memo[j][i] + 20 - arr[j][i]);
            memo[j][i + 1] = min(memo[j][i + 1], memo[j][i] + 30 - arr[j][i]);
        }
        cout << memo[0][n] << endl << endl;
    }
    return 0;
}
