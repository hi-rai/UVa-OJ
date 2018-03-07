//A problem of MCBM. Once the graph is obtained can use any of the algorithm. 
//Here Berge's augmenting path algorithm is used

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

map<string, int> ind;
int n, m, t, TC, cnt;
vector<vi> AdjList;
string str;

vi match, vis;
int Aug(int l) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (auto r: AdjList[l]) {
        if (match[r] == -1 || Aug(match[r])) {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ind["XXL"] = 0, ind["XL"] = 1, ind["L"] = 2, ind["M"] = 3;
    ind["S"] = 4, ind["XS"] = 5;
    cin >> TC;
    while (TC--) {
        cin >> n >> m, cnt = n / 6;
        AdjList.clear();
        AdjList.resize(n + m);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < 2; j++) {
                cin >> str;
                t = m + cnt * ind[str];
                for (int k = 0; k < cnt; k++)
                    AdjList[t + k].push_back(i), AdjList[i].push_back(k + t);
            }
        int MCBM = 0;
        match.assign(n + m, -1);
        for (int l = 0; l < m; l++) {
            vis.assign(n + m, 0);
            MCBM += Aug(l);
        }
        if (MCBM == m) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
