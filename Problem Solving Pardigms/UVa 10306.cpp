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
    int sq[400], y[400], TC, n, S, memo[305][305], a, b;
    for (int i = 0; i < 305; i++)
        sq[i] = i * i;
    cin >> TC;
    while (TC--) {
        cin >> n >> S;
        for (int i = 0, s = S * S; i <= S; i++)
            y[i] = (int) sqrt(s - i * i) + 1;
        for (int i = 0; i <= S; i++)
            for (int j = 0; j <= y[i]; j++)
                memo[i][j] = INF;
        memo[0][0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            for (int j = S; j >= 0; j--)
                for (int k = y[j]; k >= 0; k--)
                    if (memo[j][k] != INF)
                        for (int l = 1;; l++) {
                            int p = j + a * l, q = k + l * b;
                            if (p > S || q > y[j]) break;
                            memo[p][q] = min(memo[p][q], memo[j][k] + l);
                        }
        }
        int ans = INF;
        for (int i = 0, s = S * S; i <= S; i++) {
            int t = lower_bound(sq, sq + 305, s - i * i) - sq;
            if (t <= S && t * t + i * i == s)
                ans = min(ans, memo[i][t]);
        }
        if (ans == INF) cout << "not possible\n";
        else cout << ans << "\n";
    }
    return 0;
}
