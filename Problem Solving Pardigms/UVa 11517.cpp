#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int memo[20005], TC, p, n, t;
    cin >> TC;
    while (TC--) {
        cin >> p >> n;
        for (auto &i : memo) i = INF;
        memo[0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> t;
            for (int j = p; j >= 0; j--)
                if (j + t < 20002) memo[j + t] = min(memo[j + t], memo[j] + 1);
        }
        for (int i = p;; i++)
            if (memo[i] != INF) {
                cout << i << " " << memo[i] << endl;
                break;
            }
    }
    return 0;
}
