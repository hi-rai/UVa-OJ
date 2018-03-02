//An easy problem for finding min-cut in a graph

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
long long res[55][55], mf, f;
int s = 0, t = 1, n, m;
vi p;
bitset<55> vis;

void augment(int v, long long minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m, n && m) {
        memset(res, 0, sizeof res);
        AdjList.clear(), AdjList.resize(n);
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            AdjList[x - 1].push_back(y - 1), AdjList[y - 1].push_back(x - 1);
            res[x - 1][y - 1] = res[y - 1][x - 1] = z;
        }
        mf = 0;
        while (true) {
            queue<int> q;
            vis.reset(), f = 0, q.push(s), vis[s] = true, p.assign(n, -1);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == t) break;
                for (auto j: AdjList[u])
                    if (res[u][j] > 0 && !vis[j])
                        vis[j] = true, q.push(j), p[j] = u;
            }
            augment(t, LLONG_MAX);
            if (f == 0) break;
            mf += f;
        }
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((vis[i] ^ vis[j]) && (res[i][j] || res[j][i]))
                    cout << i + 1 << " " << j + 1 << endl;
        cout<<endl;
    }
    return 0;
}
