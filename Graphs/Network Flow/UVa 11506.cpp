//A max flow problem involving vertex capacities (normal network flow problem once the input is preprocessed).
//Split all the destroyable vertices into two and convert the graph into a directed graph (one for incoming edges and other for outgoing)
//Add internal edges from input vertex to output vertex of all the vertices that are split, with edge weight equal to that of cost of
//destroying the original vertex.
//A non destroyable vertex will serve both as its incoming and outgoing vertex.

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
int res[105][105], mf, f, s, t, M, W;
vi p;
bitset<105> vis;

inline int in(int x) {
    if (x == 1) return 0;
    return 2 * x - 3;
}

inline int out(int x) {
    if (x == M) return 2 * M - 3;
    return 2 * x - 2;
}

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
    while (cin >> M >> W, M || W) {
        memset(res, 0, sizeof res);
        AdjList.clear(), AdjList.resize(2 * M);
        s = 0, t = 2 * M - 3;
        for (int i = 1; i < M - 1; i++) {
            int x, y;
            cin >> x >> y;
            res[in(x)][out(x)] = y;
            AdjList[in(x)].push_back(out(x)), AdjList[out(x)].push_back(in(x));
        }
        for (int i = 0; i < W; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            res[out(x)][in(y)] = res[out(y)][in(x)] = z;
            AdjList[out(x)].push_back(in(y)), AdjList[out(y)].push_back(in(x));
            AdjList[in(x)].push_back(out(y)), AdjList[in(y)].push_back(out(x));
        }
        mf = 0;
        while (true) {
            queue<int> q;
            vis.reset(), f = 0, q.push(s), vis[s] = true, p.assign(2 * M, -1);
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
