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
    int M, N, arr[15][105], memo[15][105];
    while (cin >> M >> N) {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin >> arr[i][j], memo[i][j] = INT_MAX;
        for (int i = 0; i < M; i++) memo[i][N - 1] = arr[i][N - 1];
        for (int j = N - 1; j > 0; j--)
            for (int i = 0; i < M; i++) {
                int t = (i - 1 + M) % M, u = (i + 1) % M;
                memo[t][j - 1] = min(memo[t][j - 1], memo[i][j] + arr[t][j - 1]);
                memo[u][j - 1] = min(memo[u][j - 1], memo[i][j] + arr[u][j - 1]);
                memo[i][j - 1] = min(memo[i][j - 1], memo[i][j] + arr[i][j - 1]);
            }
        vector<int> ans;
        int t, minv = INT_MAX;
        for (int i = 0; i < M; i++)
            if (memo[i][0] < minv) minv = memo[i][0], t = i;
        ans.push_back(t), t = 0;
        while (t++, t != N) {
            int p, q, r, z = ans[t - 1];
            if(z == 0) p = 0, q = 1, r = M - 1;
            else if(z == M - 1) p = 0, q = M - 2, r = M - 1;
            else q = z, p = (q - 1 + M) % M, r = (q + 1) % M;
            if (memo[z][t - 1] == memo[p][t] + arr[z][t - 1]) ans.push_back(p);
            else if (memo[z][t - 1] == memo[q][t] + arr[z][t - 1]) ans.push_back(q);
            else ans.push_back(r);
        }
        for (int i = 0; i < N; i++) {
            if(i) cout << " ";
            cout << ans[i] + 1;
        }
        cout << endl << minv << endl;
    }
    return 0;
}
