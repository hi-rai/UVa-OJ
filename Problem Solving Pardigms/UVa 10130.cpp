#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n, W, G, v[1005], w[1005], memo[1005][35], TC, ans;

int calc(int id, int cw) {
    if(cw < 0)  return -INF;
    if(id >= n) return 0;
    if(memo[id][cw] != -1) return memo[id][cw];
    return memo[id][cw] = max(calc(id + 1, cw), calc(id + 1, cw - w[id]) + v[id]);
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
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> v[i] >> w[i];
        cin >> G, ans = 0;
        memset(memo, -1, sizeof memo);
        for(int i = 0; i < G; i++) {
            cin >> W;
            ans += calc(0, W);
        }
        cout << ans << endl;
    }
    return 0;
}
