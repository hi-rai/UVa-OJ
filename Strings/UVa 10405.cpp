#include<bits/stdc++.h>
using namespace std;

int memo[1100][1100], m, n;
string x, y;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (getline(cin, x), getline(cin, y), cin) {
        memset(memo, 0, sizeof memo);
        m = x.length(), n = y.length();
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
                if (x[i - 1] == y[j - 1]) memo[i][j] = max(memo[i - 1][j - 1] + 1, memo[i][j]);
            }
        cout << memo[m][n] << "\n";
    }
    return 0;
}
