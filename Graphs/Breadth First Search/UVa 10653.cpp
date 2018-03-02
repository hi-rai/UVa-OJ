//An easy problem of applcation of breadth first search on an implicit graph

#include<bits/stdc++.h>
#define MOVABLE -1
#define BOMB -2
using namespace std;

typedef pair<int,int> pii;
int R, C, rows, cols, maze[1005][1005], t, u;
pii s, d;
int adjR[]={-1,0,1,0};
int adjC[]={0,1,0,-1};
queue<pii> toVisit;

void BFS() {
    while (!toVisit.empty())    toVisit.pop();
    maze[s.first][s.second] = 0, toVisit.push(s);
    while (!toVisit.empty()) {
        pii temp = toVisit.front();
        toVisit.pop();
        for (int i = 0; i < 4; i++) {
            int r = temp.first + adjR[i], c = temp.second + adjC[i];
            if (r >= 0 && r < R && c >= 0 && c < C) {
                if (maze[r][c] != MOVABLE) continue;
                maze[r][c] = maze[temp.first][temp.second] + 1, toVisit.push(make_pair(r,c));
                if (make_pair(r, c) == d) return;
            }
        }
    }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> R >> C, R && C) {
        memset(maze, MOVABLE, sizeof maze);
        cin >> rows;
        for (int i = 0; i < rows; i++) {
            cin >> t >> cols;
            for (int j = 0; j < cols; j++)
                cin >> u, maze[t][u] = BOMB;
        }
        cin >> s.first >> s.second >> d.first >> d.second;
        BFS();
        cout << maze[d.first][d.second] << endl;
    }
    return 0;
}
