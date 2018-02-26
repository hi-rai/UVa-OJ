//A bit challanging problem
//Split each language into 26 different nodes, one for strings starting with each alphabet
//For any string add edges from the first language's node which represents the first character of the string, to all the nodes of the 
//second language, except that representing the first character of the string. Similarly, add edges from corresponding node of the
//second language to the nodes of the first language
//Finally run Dijkstra's SSSP algorithm from all the nodes of the first language, to find the shortest distance to one of the nodes 
//representing the second language. Taking minimum of the distances thus obtained (from each node of first language) to get the result

#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;

map<string, int> ind;
map<char, int> ch;
typedef pair<int, int> pii;
vector<vector<pii> > AdjList;
int M, s, d, dist[110000], ans;
string str, x, y;

void Dijkstra(int u) {
    priority_queue<pii> pq;
    for (int i = 0; i < 52 * M + 5; i++)
        dist[i] = INF;
    dist[u] = 0, pq.push(make_pair(0, u));
    while (!pq.empty()) {
        pii t = pq.top();
        pq.pop(), t.first *= -1;
        if (dist[t.second] < t.first) continue;
        if (t.second >= d && t.second < d + ch['z']) {
            ans = min(ans, t.first);
            return;
        }
        for (auto v:AdjList[t.second]) {
            if (dist[v.first] > t.first + v.second)
                dist[v.first] = t.first + v.second, pq.push(make_pair(-1 * dist[v.first], v.first));
        }
    }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    char c = 'a';
    for (int i = 0; i < 26; i++)
        ch[c++] = i;
    while (cin >> M, M) {
        int cnt = 0;
        cin >> x >> y;
        ind.clear();
        AdjList.clear();
        AdjList.resize(52 * M + 150);
        if (!ind.count(x)) ind[x] = s = cnt, cnt += 26;
        if (!ind.count(y)) ind[y] = d = cnt, cnt += 26;
        for (int i = 0; i < M; i++) {
            cin >> x >> y >> str;
            if (!ind.count(x)) ind[x] = cnt, cnt += 26;
            if (!ind.count(y)) ind[y] = cnt, cnt += 26;
            int len = str.length(), p = ind[x], q = ind[y], a = ch[str[0]];
            for (int i = 0; i < 26; i++)
                if (i != a) {
                    AdjList[p + a].push_back(make_pair(q + i, len));
                    AdjList[q + a].push_back(make_pair(p + i, len));
                }
        }
        ans = INF;
        for (int i = 0; i < 26; i++)
            Dijkstra(s + i);
        if (ans == INF) cout << "impossivel\n";
        else cout << ans << endl;
    }
    return 0;
}
