#include<bits/stdc++.h>
using namespace std;

int N, M, C, K, t;
int memo[25][205];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    while (N--) {
        memset(memo, 0, sizeof memo);
        memo[0][0] = 1;
        cin >> M >> C;
        for (int i = 1; i <= C; i++) {
            cin >> K;
            for (int j = 0; j < K; j++) {
                cin >> t;
                for (int k = 0; k <= M; k++)
                    if (memo[i - 1][k] && (k + t <= M))
                        memo[i][k + t] = 1;
            }
        }
        int ans = -1;
        for (int i = M; i >= 0; i--)
            if (memo[C][i]) {
                ans = i;
                break;
            }
        if (ans == -1) cout << "no solution\n";
        else cout << ans << "\n";
    }
    return 0;
}
