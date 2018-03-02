//An easy problem of detecting a negative cycle in a directed graph

#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;

typedef pair<int,int> pii;
vector<vector<pii> > AdjList;
int n, m, dist[1005], TC, x ,y, w;

bool BellmanFordSSSP() {
    for (auto &i:dist) i = INF;
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < AdjList[j].size(); k++)
                dist[AdjList[j][k].first] = min(dist[AdjList[j][k].first], dist[j] + AdjList[j][k].second);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < AdjList[i].size(); j++)
            if (dist[AdjList[i][j].first] > dist[i] + AdjList[i][j].second)
                return true;
    return false;
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> n >> m;
        AdjList.clear();
        AdjList.resize(n);
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> w;
            AdjList[x].push_back(make_pair(y, w));
        }
        if (BellmanFordSSSP()) cout << "possible" << endl;
        else cout << "not possible" << endl;
    }
    return 0;
}
