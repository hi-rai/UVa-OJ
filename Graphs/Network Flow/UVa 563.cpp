//A tough problem, but can be solved using the concept of maxflow in a graph with vertex capacities. However, be careful 
//Try to enumerate all the vertices of the graph (give a representative number to vertices) and create the adjacency matrix and list.
//Include a super source and a super sink.
//Now use the concept of soving max flow problems in graphs with vertex capacities (splitting each vertex into two).
//In the below solution, the three things are being done simultaneously

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef tuple<int,int,int> tiii;
map<tiii,int> ind;

vector<vi> AdjList;
int res[5500][5500], mf, f, s = 0, t = 1, r, c, b, TC;
int R[] = {-1, 0, 0, 1};
int C[] = {0, -1, 1, 0};
vi p;
bitset<5500> vis;

void augment(int v, int minEdge) {
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
    for (int i = 0; i < 52; i++)
        for (int j = 0; j < 52; j++)
            for (int k = 0; k < 2; k++)
                ind[make_tuple(i, j, k)] = t++;
    cin >> TC;
    while (TC--) {
        cin >> r >> c >> b;
        memset(res, 0, sizeof res);
        AdjList.clear(), AdjList.resize(5500);
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++) {
                int u = ind[make_tuple(i, j, 0)], v = ind[make_tuple(i, j, 1)];
                AdjList[u].push_back(v), AdjList[v].push_back(u), res[u][v] = 1;
                for (int k = 0; k < 4; k++) {
                    int x = ind[make_tuple(i + R[k], j + C[k], 0)];
                    AdjList[v].push_back(x), AdjList[x].push_back(v), res[v][x] = 1;
                }
                if (i == 1 || i == r || j == 1 || j == c)
                    AdjList[v].push_back(t), AdjList[t].push_back(v), res[v][t] = 1;
            }
        for (int i = 0; i < b; i++) {
            int x, y;
            cin >> x >> y;
            int z = ind[make_tuple(x, y, 0)];
            AdjList[s].push_back(z), AdjList[z].push_back(s), res[s][z] = 1;
        }
        mf = 0;
        while (true) {
            queue<int> q;
            vis.reset(), f = 0, q.push(s), vis[s] = true, p.assign(5500, -1);
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
        if (mf == b) cout << "possible\n";
        else cout << "not possible\n";
    }
    return 0;
}
