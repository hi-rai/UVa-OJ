//Use greedy algorithm to solve the problem
//Start from last and assume to take the next n cars (considering in reverse order) every time, continue this strategy and check 
//for any spare time that is left which can be accomodated for later (since we are considering reverse order for earlier trips)

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC, n, T, m, t[1500];
    cin >> TC;
    while (TC--) {
        cin >> n >> T >> m;
        for (int i = 0; i < m; i++)
            cin >> t[i];
        int ans = 0, et;
        ans += T, et = t[m - 1] - t[m - n - 1];
        for (int i = m - 1 - n; i >= 0; i -= n) {
            if(2 * T > et)   ans += (2 * T - et), et = 0;
            else et -= 2 * T;
            et += t[i] - t[i - n];
        }
        cout << ans + t[m - 1] << " " << (n + m - 1) / n << endl;
    }
    return 0;
}
