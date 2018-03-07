//An easy problem of counting paths in a DAG. Just take care of the directions

#include<bits/stdc++.h>
using namespace std;

int n, w, sx, sy, dx, dy, TC, x, y;
long long memo[35][35];
char dir;
pair<bool,bool> isBad[35][35];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        memset(isBad, 0, sizeof isBad);
        memset(memo, 0, sizeof memo);
        cin >> n >> sy >> sx >> dy >> dx >> w;
        dx -= sx, dy -= sy, memo[0][0] = 1;
        for (int i = 0; i < w; i++) {
            cin >> y >> x >> dir;
            x -= sx, y -= sy;
            if (x < 0 || y < 0) continue;
            if (dir == 'N') isBad[x][y].first = true;
            else if (dir == 'E') isBad[x][y].second = true;
            else if (dir == 'S' && x > 0) isBad[x - 1][y].first = true;
            else if (dir == 'W' && y > 0) isBad[x][y - 1].second = true;
        }
        for (int i = 0; i <= dx; i++)
            for (int j = 0; j <= dy; j++) {
                if (!isBad[i][j].first) memo[i + 1][j] += memo[i][j];
                if (!isBad[i][j].second) memo[i][j + 1] += memo[i][j];
            }
        cout << memo[dx][dy] << endl;
    }
    return 0;
}
