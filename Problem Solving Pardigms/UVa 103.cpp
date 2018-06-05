#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList,dim;
vi topOrder;
int n, k, t, dist[35], p[35], ans, anspos, TC = 1;
bitset<35> vis;

void TopoSort(int u) {
    vis[u] = true;
    for (auto i:AdjList[u])
        if (!vis[i]) TopoSort(i);
    topOrder.push_back(u);
    return;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> k >> n, cin) {
        AdjList.clear(), AdjList.resize(k);
        dim.clear(), dim.resize(k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++)
                cin >> t, dim[i].push_back(t);
            sort(dim[i].begin(), dim[i].end());
            for (int p = 0; p < i; p++) {
                bool check = true;
                int temp = (dim[p][0] < dim[i][0] ? -1 : 1);
                if (dim[p][0] == dim[i][0]) check = false;
                for (int j = 1; j < n && check; j++) {
                    if (dim[p][j] >= dim[i][j] && temp == -1) check = false;
                    if (dim[p][j] <= dim[i][j] && temp == 1) check = false;
                }
                if (check) {
                    if (temp == 1) AdjList[p].push_back(i);
                    else AdjList[i].push_back(p);
                }
            }
        }
        vis.reset(), ans = 1, memset(dist, -1, sizeof dist), memset(p, -1, sizeof p);
        topOrder.clear();
        for (int i = 0; i < k; i++)
            if (!vis[i]) TopoSort(i), dist[i] = 1, p[i] = -1;
        for (int i = topOrder.size() - 1; i >= 0; i--)
            for (auto j : AdjList[topOrder[i]]) {
                if (dist[j] < dist[topOrder[i]] + 1) {
                    dist[j] = dist[topOrder[i]] + 1, p[j] = topOrder[i];
                    if (ans < dist[j]) ans = dist[j], anspos = j;
                }
            }
        cout << ans << endl;
        for (int i = anspos; i != -1; i = p[i]) {
            if (i != anspos) cout << " ";
            cout << i + 1;
        }
        cout << endl;
    }
    return 0;
}
