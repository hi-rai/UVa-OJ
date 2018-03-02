//An easy application of breadth first search

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int maze[2005][2005], dist[2005][2005], m, n, ans, t, u, d;
int r[] = {-1, 0, 0, 1};
int c[] = {0, -1, 1, 0};
queue<pii> q;

void calc() {
    pii temp;
    bool found = false;
    while (!q.empty() && !found) {
        temp = q.front(), q.pop(), d = dist[temp.first][temp.second];
        for (int i = 0; i < 4; i++) {
            int u = temp.first + r[i], v = temp.second + c[i];
            if (u < 0 || u > 2000 || v < 0 || v > 2000) continue;
            if (maze[u][v] == 1) continue;
            if (maze[u][v] == 2) {
                found = true;
                ans = d + 1;
                break;
            }
            maze[u][v] = 1, q.push(make_pair(u, v)), dist[u][v] = d + 1;
        }
    }
    while (!q.empty()) q.pop();
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> m, m) {
        memset(maze, 0, sizeof maze);
        for (int i = 0; i < m; i++)
            cin >> t >> u, maze[t][u] = 1, q.push(make_pair(t, u)), dist[t][u] = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> t >> u, maze[t][u] = 2;
        calc();
        cout << ans << endl;
    }
    return 0;
}
