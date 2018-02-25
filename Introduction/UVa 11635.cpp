//A difficult problem unless you realise that it can be easily solved using two step approach
//First find a modified adjacency list consisting of vertices having hotels (use Dijkstra's Algorithm to find other stopping vertices
//within range of 600 minutes)
//Then use BFS in this modified graph

#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;

typedef pair<int,int> pii;
vector<vector<pii>> AdjList;
vector<vector<int> > ModAdjList;
vector<int> dist;

int n, m, h, t, u, v;
bitset<10005> isHotel;

void dijkstra(int u) {
    priority_queue<pii> pq;
    dist.assign(n, INF);
    dist[u] = 0;
    pq.push(make_pair(0, u));
    while (!pq.empty()) {
        pii t = pq.top();
        pq.pop(), t.first *= -1;
        if (dist[t.second] < t.first) continue;
        if (t.second != u && isHotel[t.second]) ModAdjList[u].push_back(t.second);
        for (auto temp: AdjList[t.second]) {
            if (dist[temp.first] > t.first + temp.second && t.first + temp.second <= 600)
                pq.push(make_pair(-1 * (t.first + temp.second), temp.first)), dist[temp.first] = t.first + temp.second;
        }
    }
    return;
}

void BFS(int u) {
    dist.assign(n, INF);
    queue<int> toVisit;
    toVisit.push(u), dist[u] = 0;
    while (!toVisit.empty()) {
        int t = toVisit.front();
        toVisit.pop();
        for (auto i:ModAdjList[t])
            if (dist[i] == INF) {
                dist[i] = dist[t] + 1, toVisit.push(i);
                if (i == n - 1) return;
            }
    }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n) {
        isHotel.reset();
        AdjList.clear(), ModAdjList.clear();
        AdjList.resize(n), ModAdjList.resize(n);
        cin >> h;
        for (int i = 0; i < h; i++)
            cin >> t, isHotel[t - 1] = true;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> t >> u >> v;
            AdjList[t - 1].push_back(make_pair(u - 1, v));
            AdjList[u - 1].push_back(make_pair(t - 1, v));
        }
        isHotel[0] = isHotel[n - 1] = true;
        for (int i = 0; i < n; i++)
            if (isHotel[i]) dijkstra(i);
        BFS(0);
        if (dist[n - 1] == INF) cout << "-1" << endl;
        else cout << dist[n - 1] - 1 << endl;
    }
    return 0;
}
