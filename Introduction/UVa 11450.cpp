//an easy DP problem (can be solved easily by both bottom-up and top-down approach)

//Bottom-up solution
#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC, M, C, K, c[25];
    bitset<205> memo[25];
    cin >> TC;
    while(TC--) {
        cin >> M >> C;
        memo[0].reset(), memo[0][0] = true;
        for(int i = 1; i <= C; i++) {
            cin >> K;
            for (int j = 0; j < K; j++)
                cin >> c[j];
            memo[i].reset();
            for (int j = 0; j < M; j++)
                if (memo[i - 1][j])
                    for (int k = 0; k < K; k++)
                        if (j + c[k] <= M)
                            memo[i][j + c[k]] = true;
        }
        int ans = -1;
        for(int i = M; i >= 0 && ans == -1; i--)
            if(memo[C][i])  ans = i;
        if(ans == -1)   cout << "no solution" << endl;
        else cout << ans << endl;
    }
    return 0;
}

//Top-down solution
/*
#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int TC, M, C, c[25][25], ans, memo[25][205];

int calc(int mon, int cl) {
    if(mon > M) return -INF;
    if(cl == C) {
        ans = max(ans, mon);
        return mon;
    }
    if(memo[cl][mon] != -1) return memo[cl][mon];
    int v = -INF;
    for(int i = 1; i <= c[cl][0]; i++)
        v = max(calc(mon + c[cl][i], cl + 1), v);
    return memo[cl][mon] = v;
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
        cin >> M >> C;
        memset(memo, -1, sizeof memo);
        for(int  i = 0; i < C; i++) {
            cin >> c[i][0];
            for (int j = 1; j <= c[i][0]; j++)
                cin >> c[i][j];
        }
        ans = -1, calc(0, 0);
        if(ans == -1)   cout << "no solution" << endl;
        else cout << ans << endl;
    }
    return 0;
}*/
