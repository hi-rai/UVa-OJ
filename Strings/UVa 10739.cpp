#include<bits/stdc++.h>
using namespace std;

int memo[1010][1010], m, tc = 1, TC;
string x;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> TC, cin.ignore();
    while (TC--) {
        getline(cin, x), m = x.length();
        memset(memo, 0, sizeof memo);
        for(int i = 0; i <= m; i++)
            memo[0][i] = memo[i][0] = i;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++) {
                memo[i][j] = min(memo[i - 1][j], memo[i][j - 1]) + 1;
                if (x[i - 1] == x[m - j]) memo[i][j] = min(memo[i][j], memo[i - 1][j - 1]);
                else memo[i][j] = min(memo[i][j], memo[i - 1][j - 1] + 1);
            }
        cout << "Case " << tc++ << ": " << memo[m][m] / 2 << "\n";
    }
    return 0;
}
