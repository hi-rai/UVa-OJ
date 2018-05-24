//This question can be easily solved using DP

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int memo[101][10][1024];

void calc() {
    memset(memo, 0, sizeof memo);
    for (int i = 1; i < 10; i++)
        memo[1][i][1 << i] = 1;
    for (int i = 1; i < 100; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 1024; k++) {
                int temp = memo[i][j][k];
                if (temp) {
                    if (j) memo[i + 1][j - 1][k | (1 << (j - 1))] = (memo[i + 1][j - 1][k | (1 << (j - 1))] + temp) % MOD;
                    if (j != 9) memo[i + 1][j + 1][k | (1 << (j + 1))] = (memo[i + 1][j + 1][k | (1 << (j + 1))] + temp) % MOD;
                }
            }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    calc();
    int TC, N, M;
    cin >> TC;
    while (TC--) {
        cin >> N >> M;
        int ans = 0, t = (1 << N) - 1;
        for (int i = 0; i <= M; i++)
            for (int j = 0; j < N; j++)
                ans = (ans + memo[i][j][t]) % MOD;
        cout << ans << endl;
    }
    return 0;
}
