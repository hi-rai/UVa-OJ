//An easy problem of finding shortest paths on DAG. The graph is already given in topologically sorted order.
//So, no need to create adjacency list, just implicictly process the information

#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;

int n, m, t, dist[2000];
string tc;

inline int ind(int floor, int ladder) {
    return (floor - 1) * m + ladder;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> tc >> n >> m, cin) {
        for (int i = 0; i < 2000; i++)
            dist[i] =INF;
        for (int i = ind(1, 0), k = ind(1, m - 1); i <= k; i++)
            dist[i] = 0;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < m; k++)
                    cin >> t, dist[ind(i, k)] = min(dist[ind(i, k)], dist[ind(i - 1, j)] + t + 2);
        int ans = INF;
        for (int i = 0; i < m; i++)
            ans = min(ans, dist[ind(n, i)]);
        cout << tc << "\n" << ans << "\n";
    }
    return 0;
}
