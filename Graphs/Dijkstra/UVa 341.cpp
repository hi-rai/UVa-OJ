//An easy problem, with application of Dijkstra's Algorithm

#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;

typedef pair<int,int> pii;

vector<vector<pii> > AdjList;
int N, M, S, D, dist[15], parent[15];

void DijkstraSSSP(int u) {
    priority_queue<pii> pq;
    for (int i = 0; i < 15; i++)
        parent[i] = -1, dist[i] = INF;
    dist[u] = 0;
    pq.push(make_pair(0, u));
    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop(), top.first *= -1;
        if (dist[top.second] < top.first) continue;
        if (top.second == D) return;
        for (auto temp:AdjList[top.second]) {
            if (dist[temp.first] > top.first + temp.second) {
                dist[temp.first] = top.first + temp.second;
                pq.push(make_pair(-1 * dist[temp.first], temp.first));
                parent[temp.first] = top.second;
            }
        }
    }
    return;
}

int main() {
    int x, y, TC = 1;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while (cin >> N, N) {
        AdjList.clear();
        AdjList.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> M;
            for (int j = 0; j < M; j++) {
                cin >> x >> y;
                AdjList[i].push_back(make_pair(x - 1, y));
            }
        }
        cin >> S >> D;
        S--, D--;
        DijkstraSSSP(S);
        vector<int> path;
        for (int i = D; i != parent[S]; i = parent[i])
            path.push_back(i);
        cout << "Case " << TC++ << ": Path =";
        for (int i = path.size() - 1; i >= 0; i--)
            cout << " " << path[i] + 1;
        cout << "; " << dist[D] << " second delay" << endl;
    }
    return 0;
}
