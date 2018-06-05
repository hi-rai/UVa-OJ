//Though its given that the graph is connected, got WA when considered the graph as connected. Handling the case when the graph is
//disconnected gives AC. Or there might we issue with some particular cases because of which it gets WA - there are two conditions
//mentioned in the question 1 ≤ i ≤ N and 1 ≤ ni ≤ N − 1. If we consider the second one then 2 <= N, however first condition says
//N can be 1, for which if we take ni ≤ N − 1 then ni ≤ 0

#include<bits/stdc++.h>
using namespace std;

vector<int> AdjList[1005], c[1005];
int n, t, u, vis[1005], memo[1005][2], ans;

void dfs(int x) {
    vis[x] = 1;
    for(auto t: AdjList[x])
        if(!vis[t]) dfs(t), c[x].push_back(t);
}

int calc(int x, int f) {
    if (memo[x][f] != -1) return memo[x][f];
    int p = 0, q = 0;
    for (auto t : c[x]) p += calc(t, 0);
    if (f == 1) return memo[x][f] = 1 + p;
    for (auto t : c[x]) q += calc(t, 1);
    return memo[x][f] = min(q, p + 1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> t;
            AdjList[i].clear(), c[i].clear();
            for (int j = 0; j < t; j++)
                cin >> u, AdjList[i].push_back(u - 1);
        }
        memset(vis, 0, sizeof vis), ans = 0;
        memset(memo, -1, sizeof memo);
        for(int i = 0; i < n; i++)
            if(vis[i] == 0) {
                dfs(i);
                ans += max(1, calc(i, 0));
            }
        cout << ans << endl;
    }
    return 0;
}
