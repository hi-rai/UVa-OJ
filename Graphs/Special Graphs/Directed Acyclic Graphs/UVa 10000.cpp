//An easy problem of finding single source longest path in a DAG.
//First find the topological order of vertices from the source then relax the edges according to the sorted order

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi topOrder;
int n, s, p, q, dist[105], ans, anspos, TC = 1;
bitset<105> vis;

void TopoSort(int u) {
    vis[u] = true;
    for (auto i:AdjList[u])
        if (!vis[i]) TopoSort(i);
    topOrder.push_back(u);
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n) {
        AdjList.clear(), AdjList.resize(n);
        cin >> s;
        while (cin >> p >> q, p || q)
            AdjList[p - 1].push_back(q - 1);
        vis.reset(), topOrder.clear();
        TopoSort(s - 1);
        memset(dist, -1, sizeof dist), dist[s - 1] = 0, ans = 0, anspos = s - 1;
        for (int i = topOrder.size() - 1; i >= 0; i--)
            for (auto j:AdjList[topOrder[i]]) {
                dist[j] = max(dist[j], dist[topOrder[i]] + 1);
                if (dist[j] > ans) ans = dist[j], anspos = j;
                else if (dist[j] == ans) anspos = min(anspos, j);
            }
        cout << "Case " << TC++ << ": The longest path from " << s << " has length " << ans << ", finishing at "
             << anspos + 1 << ".\n\n";
    }
    return 0;
}
