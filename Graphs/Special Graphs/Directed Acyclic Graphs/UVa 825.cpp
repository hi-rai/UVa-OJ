//A simple problem of finding number of paths in an implicit DAG

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int n, m, t, u, TC;
vector<vi> memo,isBad;
string str;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> n >> m;
        memo.assign(n + 1, vi(m + 1, 0));
        isBad.assign(n, vi(m, 0));
        cin.ignore();
        while (getline(cin, str), str.length() && cin) {
            stringstream in;
            in << str;
            in >> t;
            while (in >> u)
                isBad[t - 1][u - 1] = 1;
        }
        memo[0][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!isBad[i][j])
                    memo[i + 1][j] += memo[i][j], memo[i][j + 1] += memo[i][j];
        cout << memo[n - 1][m - 1] << endl;
        if (TC) cout << endl;
    }
    return 0;
}
