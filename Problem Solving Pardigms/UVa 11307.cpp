#include<bits/stdc++.h>
using namespace std;

vector<int> AdjList[10005];
int n, t, root, memo[10005][10], ans;
bitset<10005> r;
string str, ign;

int calc(int v, int t) {
    if (memo[v][t] != -1) return memo[v][t];
    int ret = INT_MAX;
    for (int i = 1; i < 7; i++)
        if (t != i) {
            int temp = 0;
            for (auto p : AdjList[v])
                temp += calc(p, i);
            ret = min(temp + i, ret);
        }
    return memo[v][t] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> n, n) {
        cin.ignore(), r.set();
        for (int i = 0; i < n; i++) {
            AdjList[i].clear();
            getline(cin, str);
            stringstream in;
            in << str;
            in >> ign;
            while (in >> t)
                AdjList[i].push_back(t), r[t] = false;
        }
        memset(memo, -1, sizeof memo);
        root = -1, ans = INT_MAX;
        for (int i = 0; i < n && root == -1; i++)
            if (r[i]) root = i;
        for(int i = 1; i < 7; i++)
            ans = min(ans, calc(root, i));
        cout << ans << endl;
    }
    return 0;
}
