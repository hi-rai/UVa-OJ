//A good problem on the application of breadth first search
//The problem can be solved using two BFSs running in parallel, on the implicit graph of the maze (slightly take care of the boundary 
//conditions)

#include<bits/stdc++.h>
#define INF 1000000000
#define ONFIRE -1
#define WALL 0
#define CANPASS 1
#define PASSED 2
using namespace std;

typedef pair<int,int> pii;

int maze[1005][1005], R, C, TC, ans;
int r[] = {-1, 0, 0, 1};
int c[] = {0, -1, 1, 0};
char ch;
pii comp = make_pair(-1, -1), temp;
queue<pii> qFire, qJoe;

void calc() {
    ans = 0;
    bool check = true, found = false;
    temp = qJoe.front();
    int u = temp.first, v = temp.second;
    if (u <= 0 || u >= R-1 || v <= 0 || v >= C-1)   found=true;
    while(check && !found) {
        check = false;
        ans++;
        qFire.push(comp), qJoe.push(comp);
        temp = qFire.front(), qFire.pop();
        while (temp != comp) {
            for (int i = 0; i < 4; i++) {
                u = temp.first + r[i], v = temp.second + c[i];
                if (u < 0 || u >= R || v < 0 || v >= C) continue;
                if (maze[u][v] == CANPASS || maze[u][v] == PASSED)
                    maze[u][v] = ONFIRE, qFire.push(make_pair(u, v));
            }
            if (!qFire.empty()) temp = qFire.front(), qFire.pop();
            else qFire.push(comp);
        }
        temp = qJoe.front(), qJoe.pop();
        while (temp != comp && !found) {
            for (int i = 0; i < 4; i++) {
                u = temp.first + r[i], v = temp.second + c[i];
                if (maze[u][v] == CANPASS) {
                    if (u <= 0 || u >= R-1 || v <= 0 || v >= C-1) {
                        found = true;
                        break;
                    }
                    maze[u][v] = PASSED, qJoe.push(make_pair(u, v)), check = true;
                }
            }
            if (!qJoe.empty()) temp = qJoe.front(), qJoe.pop();
            else qJoe.push(comp);
        }
    }
    if (!found) ans = INF;
    else ans++;
    while (!qFire.empty()) qFire.pop();
    while (!qJoe.empty()) qJoe.pop();
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> R >> C;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                cin >> ch;
                if (ch == '#') maze[i][j] = WALL;
                else if (ch == 'F') maze[i][j] = ONFIRE, qFire.push(make_pair(i, j));
                else if (ch == '.') maze[i][j] = CANPASS;
                else qJoe.push(make_pair(i, j)), maze[i][j] = PASSED;
            }
        calc();
        if (ans == INF) cout << "IMPOSSIBLE\n";
        else cout << ans << endl;
    }
    return 0;
}
