#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> AdjList;
vi changed[105];
int blk[100], p[100], cnt, ans, TC, n, k, a, b;

void solve(int t) {
    if(t == n) {
        if(cnt > ans) {
            for (int i = 0; i < n; i++)
                blk[i] = p[i];
            ans = cnt;
        }
        return;
    }
    solve(t + 1);
    if(p[t]) {
        cnt++;
        changed[t].clear();
        for(auto i : AdjList[t])
            if (p[i]) changed[t].push_back(i), p[i] = 0;
        solve(t + 1);
        for(auto i : changed[t]) p[i] = 1;
        cnt--;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> n >> k;
        AdjList.clear(), AdjList.resize(n);
        memset(blk, 0, sizeof blk), cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) p[i] = 1;
        while (k--)
            cin >> a >> b, AdjList[a - 1].push_back(b - 1), AdjList[b - 1].push_back(a - 1);
        solve(0);
        cout << ans << endl;
        for (int i = 0, j = 0; i < n; i++)
            if (blk[i]) {
                cout << i + 1, j++;
                if (j != ans) cout << " ";
            }
        cout << endl;
    }
    return 0;
}
