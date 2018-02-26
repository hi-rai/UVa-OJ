//Application of Dijkstra's Algorithm. Consider reverse motion of the lift too and add extra overhead of 60 seconds for changing the lifts

#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
vector<vector<pii> > AdjList;
int t[5], n, k, x, dist[100];
string str;

void Dijkstra(int u) {
    priority_queue<pii> pq;
    for (int i = 0; i < 100; i++)
        dist[i] = INF;
    dist[u] = 0, pq.push(make_pair(0, u));
    while (!pq.empty()) {
        pii t = pq.top();
        pq.pop(), t.first *= -1;
        if (dist[t.second] < t.first) continue;
        if (t.second == k) return;
        for (auto v:AdjList[t.second]) {
            if (dist[v.first] > t.first + v.second)
                dist[v.first] = t.first + v.second, pq.push(make_pair(-1 * dist[v.first], v.first));
        }
    }
    return;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> k, cin) {
        AdjList.clear();
        AdjList.resize(100);
        for (int i = 0; i < n; i++)
            cin >> t[i];
        cin.ignore();
        for (int i = 0; i < n; i++) {
            getline(cin, str);
            stringstream in;
            in << str;
            vi temp;
            while (in >> x)
                temp.push_back(x);
            sort(temp.begin(), temp.end());
            for (int j = 0; j < temp.size(); j++) {
                for (int k = j + 1; k < temp.size(); k++) {
                    int p = temp[j], q = temp[k];
                    if (p) AdjList[p].push_back(make_pair(q, t[i] * (temp[k] - temp[j]) + 60));
                    else AdjList[p].push_back(make_pair(q, (t[i] * (temp[k] - temp[j]))));
                    AdjList[q].push_back(make_pair(p, t[i] * (temp[k] - temp[j]) + 60));
                }
            }
        }
        Dijkstra(0);
        if (dist[k] == INF) cout << "IMPOSSIBLE\n";
        else cout << dist[k] << endl;
    }
    return 0;
}
