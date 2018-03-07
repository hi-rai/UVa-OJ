//A very easy problem of counting paths in a DAG

#include<bits/stdc++.h>
using namespace std;

vector<int> memo;
int n, m, t, ans;
bool check=false;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, cin) {
        if (check) cout << endl;
        else check = true;
        memo.assign(n, 0);
        memo[0] = 1, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++)
                cin >> t, memo[t] += memo[i];
            if (!m) ans += memo[i];
        }
        cout << ans << endl;
    }
    return 0;
}
