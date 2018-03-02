//An easy application of BFS, but requires a careful preprocessing
//take care of the node identifiers, and also that whether the node during the query was alredy mentioned while giving links

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > AdjList;
queue<int> toVisit;
map<int,int> _index_;
int NC, _max_, reachable, source, ind, x, y, TC = 1, dist[50];

void BFS(int u) {
    while (!toVisit.empty()) toVisit.pop();
    memset(dist, -1, sizeof dist);
    dist[u] = 0, toVisit.push(u), reachable = 1;
    while (!toVisit.empty()) {
        x = toVisit.front(), toVisit.pop();
        if (dist[x] == _max_) return;
        for (auto t:AdjList[x])
            if (dist[t] == -1) dist[t] = dist[x] + 1, toVisit.push(t), reachable++;
    }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> NC, NC) {
        ind = 0, _index_.clear();
        AdjList.clear(), AdjList.resize(35);
        for (int i = 0; i < NC; i++) {
            cin >> x >> y;
            if (!_index_.count(x)) _index_[x] = ind++;
            if (!_index_.count(y)) _index_[y] = ind++;
            AdjList[_index_[x]].push_back(_index_[y]);
            AdjList[_index_[y]].push_back(_index_[x]);
        }
        while (cin >> source >> _max_, source || _max_) {
            if (_index_.count(source))
                BFS(_index_[source]), cout << "Case " << TC++ << ": " << ind - reachable
                                           << " nodes not reachable from node " << source << " with TTL = " << _max_
                                           << "." << endl;
            else
                cout << "Case " << TC++ << ": " << ind << " nodes not reachable from node " << source << " with TTL = "
                     << _max_ << "." << endl;
        }
    }
    return 0;
}
