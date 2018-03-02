//An easy application of BFS in 3D implicit graph

#include<bits/stdc++.h>
#define ROCK -2
#define MOVABLE -1
using namespace std;

typedef tuple<int,int,int> tiii;

int maze[35][35][35], L, R, C, ans, d;
int l[] = {-1, 0, 0, 0, 0, 1};
int r[] = {0, -1, 0, 0, 1, 0};
int c[] = {0, 0, -1, 1, 0, 0};
char ch;
queue<tiii> q;
tiii dest;

void calc() {
    tiii temp;
    bool found = false;
    while (!q.empty() && !found) {
        temp = q.front(), q.pop(), d = maze[get<0>(temp)][get<1>(temp)][get<2>(temp)];
        for (int i = 0; i < 6; i++) {
            int u = get<0>(temp) + l[i], v = get<1>(temp) + r[i], w = get<2>(temp) + c[i];
            if (u < 0 || u > L || v < 0 || v > R || w < 0 || w > C || maze[u][v][w] != MOVABLE) continue;
            if (make_tuple(u, v, w) == dest) ans = d + 1, found = true;
            maze[u][v][w] = d + 1, q.push(make_tuple(u, v, w));
        }
    }
    while (!q.empty()) q.pop();
    if (!found) ans = -1;
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> L >> R >> C, L) {
        for (int i = 0; i < L; i++)
            for (int j = 0; j < R; j++)
                for (int k = 0; k < C; k++) {
                    cin >> ch;
                    if (ch == '#') maze[i][j][k] = ROCK;
                    else if (ch == 'S') q.push(make_tuple(i, j, k)), maze[i][j][k] = 0;
                    else if (ch == 'E') dest = make_tuple(i, j, k), maze[i][j][k] = MOVABLE;
                    else maze[i][j][k] = MOVABLE;
                }
        calc();
        if (ans != -1) cout << "Escaped in "<<ans<<" minute(s).\n";
        else cout << "Trapped!" << endl;
    }
    return 0;
}
