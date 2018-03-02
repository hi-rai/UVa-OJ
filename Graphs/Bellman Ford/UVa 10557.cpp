//An application of (modified) Bellman Ford and BFS

#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;

vector<vector<int> > AdjList;
int n, dist[105], energy[105], tot, t;
queue<int> toVisit;
bool vis[105];

bool BFS(int source) {
    bitset<105> visited;
    toVisit.push(source), visited[source] = true;
    while (!toVisit.empty()) {
        t = toVisit.front(), toVisit.pop();
        for (auto i:AdjList[t])
            if (!visited[i]) toVisit.push(i), visited[i] = true;
    }
    if (source == 0)
        for (int i = 0; i < n; i++)
            vis[i] = visited[i];
    return visited[n - 1];
}

bool BellmanFord() {
    for (auto &i:dist) i = INF;
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n; j++)
            for (auto k:AdjList[j])
                if (dist[j] + energy[k] < dist[k] && dist[j] + energy[k] < 100)
                    dist[k] = dist[j] + energy[k];
    if (dist[n - 1] < 100) return true;
    BFS(0);
    for (int i = 0; i < n; i++)
        for (auto j:AdjList[i])
            if (dist[i] + energy[j] < dist[j] && dist[i] + energy[j] < 100)
                if (vis[i] && BFS(i)) return true;
    return false;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n != -1) {
        AdjList.clear(),AdjList.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> energy[i] >> tot, energy[i] *= -1;
            for (int j = 0; j < tot; j++)
                cin >> t, AdjList[i].push_back(t - 1);
        }
        if (BellmanFord()) cout << "winnable" << endl;
        else cout << "hopeless" << endl;
    }
    return 0;
}
