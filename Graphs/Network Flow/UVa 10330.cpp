//An application of FordFulkerson's algorithm of max flow in a directed graph, with vertex capacities and multiple sources and sinks

#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef vector<int> vi;
int N, M, mf, f, s=0, t=249, x, y, w, B, D, res[250][250];
vector<vi> AdjList;
vi p;
bitset<250> vis;

void augment(int u,int minflow) {
    if (u == s) {
        f = minflow;
        return;
    } else if (p[u] != -1) {
        augment(p[u], min(minflow, res[p[u]][u]));
        res[p[u]][u] -= f;
        res[u][p[u]] += f;
    }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> N, cin) {
        memset(res, 0, sizeof res);
        AdjList.clear(), AdjList.resize(250);
        for (int i = 1; i <= N; i++)
            cin >> w, AdjList[2 * i - 1].push_back(2 * i), AdjList[2 * i].push_back(2 * i - 1), res[2 * i - 1][2 *
                                                                                                               i] = w;
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> x >> y >> w;
            if (!res[2 * x][2 * y - 1]) AdjList[2 * x].push_back(2 * y - 1), AdjList[2 * y - 1].push_back(2 * x);
            res[2 * x][2 * y - 1] += w;
        }
        cin >> B >> D;
        for (int i = 0; i < B; i++)
            cin >> x, AdjList[s].push_back(2 * x - 1), AdjList[2 * x - 1].push_back(s), res[s][2 * x - 1] = INF;
        for (int i = 0; i < D; i++)
            cin >> x, AdjList[t].push_back(2 * x), AdjList[2 * x].push_back(t), res[2 * x][t] = INF;
        mf = 0;
        while (true) {
            queue<int> q;
            vis.reset(), f = 0, q.push(s), vis[s] = true, p.assign(250, -1);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == t) break;
                for (auto j: AdjList[u])
                    if (res[u][j] > 0 && !vis[j])
                        vis[j] = true, q.push(j), p[j] = u;
            }
            augment(t, INT_MAX);
            if (f == 0) break;
            mf += f;
        }
        cout << mf << endl;
    }
    return 0;
}
