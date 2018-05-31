#include<bits/stdc++.h>
#define INF 10000000
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
vector<vi> mat;
vector<vb> used;
int r, c, sc, ec, TC;

void solve(int x, int y, int k, int n) {
    if (x == r - 1) { ec = min(y + 1, ec); return; }
    k++, used[x][y] = true;
    if (k > n) k = 1, n++;
    if (y - 1 >= 0 && !used[x][y - 1] && mat[x][y - 1] == k) solve(x, y - 1, k, n);
    if (y + 1 < c && !used[x][y + 1] && mat[x][y + 1] == k) solve(x, y + 1, k, n);
    if (x - 1 >= 0 && !used[x - 1][y] && mat[x - 1][y] == k) solve(x - 1, y, k, n);
    if (x + 1 < r && !used[x + 1][y] && mat[x + 1][y] == k) solve(x + 1, y, k, n);
    used[x][y] = false;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> r >> c;
        mat.assign(r, vi(c));
        used.assign(r, vb(c, false));
        for(int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> mat[i][j];
        ec = INF;
        for(int i = 0; i < c && ec == INF; i++)
            if(mat[0][i] == 1)
                solve(0, i, 1, 1), sc = i + 1;
        cout << "1 " << sc << endl;
        cout << r << " " << ec << endl;
        if(TC)  cout << endl;
    }
    return 0;
}
