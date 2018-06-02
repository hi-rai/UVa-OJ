//classical knapsack problem, but additionally we have to remember the things you have picked. For this we can use bitmask

#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;

int n, p, W, v[35], w[35], memo[35][1005], chosen[35][1005], cnt = 0;

pii calc(int id, int cw) {
    if (cw < 0) return pii(-INF, 0);
    if (id >= n) return pii(0, 0);
    if (memo[id][cw] != -1) return pii(memo[id][cw], chosen[id][cw]);
    pii a = calc(id + 1, cw), b = calc(id + 1, cw - w[id]);
    if (a.first > b.first + v[id]) memo[id][cw] = a.first, chosen[id][cw] = a.second;
    else memo[id][cw] = b.first + v[id], chosen[id][cw] = (b.second | (1 << id));
    return pii(memo[id][cw], chosen[id][cw]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    bool ch = true;
    while(cin >> W >> p) {
        if(ch) ch = false;
        else cout << endl;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> w[i] >> v[i], w[i] *= 3 * p;
        memset(memo, -1, sizeof memo);
        memset(chosen, 0, sizeof chosen);
        pii ans = calc(0, W);
        cnt = 0;
        for(int i = 0; i < n; i++)
            if(ans.second & (1 << i)) cnt++;
        cout << ans.first << endl;
        cout << cnt << endl;
        for(int i = 0; i < n; i++)
            if(ans.second & (1 << i))
                cout << w[i] / 3 / p << " " << v[i] << endl;
    }
    return 0;
}
