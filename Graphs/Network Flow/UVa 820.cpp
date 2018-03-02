//An easy network flow problem

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
int res[105][105], mf, f, s, t, n, c, TC = 1;
vi p;

void augment(int v, int minEdge) {
    if (v == s - 1) {
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
    while (cin >> n, n) {
        cin >> s >> t >> c;
        memset(res, 0, sizeof res);
        AdjList.clear(), AdjList.resize(n);
        for (int i = 0; i < c; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            if (res[x - 1][y - 1]==0) AdjList[x - 1].push_back(y - 1), AdjList[y - 1].push_back(x - 1);
            res[x - 1][y - 1] += z, res[y - 1][x - 1] += z;
        }
        mf = 0;
        while (true) {
            bitset<105> vis;
            queue<int> q;
            vis.reset(), f = 0, q.push(s - 1), vis[s-1] = true, p.assign(n, -1);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == t-1) break;
                for (auto j: AdjList[u])
                    if (res[u][j] > 0 && !vis[j])
                        vis[j] = true, q.push(j), p[j] = u;
            }
            augment(t - 1, INT_MAX);
            if (f == 0) break;
            mf += f;
        }
        cout << "Network " << TC++ << "\nThe bandwidth is " << mf << ".\n\n";
    }
    return 0;
}
