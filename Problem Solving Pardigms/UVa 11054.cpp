#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, t;
    while(cin >> n, n) {
        long long sum = 0, ans = 0;
        for(int i = 0; i < n; i++)
            cin >> t, sum += t, ans += abs(sum);
        cout << ans << endl;
    }
    return 0;
}
