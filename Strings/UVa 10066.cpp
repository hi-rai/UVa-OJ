#include<bits/stdc++.h>
using namespace std;

int memo[110][110], m, n, tc = 1, A[110], B[110];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while(cin >> m >> n, m) {
        for(int i = 0; i < m; i++)  cin >> A[i];
        for(int j = 0; j < n; j++)  cin >> B[j];
        memset(memo, 0, sizeof memo);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) {
            memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            if(A[i - 1] == B[j - 1])    memo[i][j] = max(memo[i - 1][j - 1] + 1, memo[i][j]);
        }
        cout << "Twin Towers #" << tc++ << "\nNumber of Tiles : " << memo[m][n] << "\n\n";
    }
    return 0;
}
