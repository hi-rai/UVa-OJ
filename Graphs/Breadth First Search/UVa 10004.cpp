//An easy problem

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > AdjList;
int n, l, t, u, dist[205];
queue<int> toVisit;

bool BFS(int u) {
    while (!toVisit.empty())
        toVisit.pop();
    dist[u] = 0, toVisit.push(u);
    while (!toVisit.empty()) {
        t = toVisit.front(), toVisit.pop();
        for (auto v:AdjList[t]) {
            if (dist[v] == -1)  dist[v] = dist[t] + 1, toVisit.push(v);
            else if (!((dist[t] ^ dist[v]) & 1))   return false;
        }
    }
    return true;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n) {
        cin >> l;
        AdjList.clear();
        AdjList.resize(n);
        memset(dist, -1, sizeof dist);
        for (int i = 0; i < l; i++)
            cin >> t >> u, AdjList[t].push_back(u), AdjList[u].push_back(t);
        if (BFS(0))
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}
