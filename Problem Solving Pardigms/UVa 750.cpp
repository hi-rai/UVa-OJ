#include<bits/stdc++.h>
using namespace std;

int soln[100][10], cnt = 0, d[35], r[10];

void solve(int n) {
    if (n == 9) {
        cnt++;
        for(int i = 1; i < 9; i++)  soln[cnt][i] = soln[cnt - 1][i];
        return;
    }
    for (int i = 1; i < 9; i++)
        if (r[i] == 0 && d[n + i] == 0 && d[i - n + 24] == 0) {
            r[i] = d[n + i] = d[i - n + 24] = 1;
            soln[cnt][n] = i;
            solve(n + 1);
            r[i] = d[n + i] = d[i - n + 24] = 0;
        }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve(1);
    int TC, x, y;
    cin >> TC;
    while(TC--) {
        cin >> x >> y;
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
        for(int i = 0, j = 1; i < cnt; i++)
            if(soln[i][y] == x) {
            cout << setw(2) << j++ << "     ";
            for(int k = 1; k < 9; k++)
                cout << " " << soln[i][k];
            cout << endl;
        }
        if(TC) cout << endl;
    }
    return 0;
}
