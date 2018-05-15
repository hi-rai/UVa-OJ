//A very easy problem

#include<bits/stdc++.h>
using namespace std;

int ans, n, x, y, h, w, v, t;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n) {
        v = -1;
        for (int i = 0; i < n; i++) {
            cin >> h >> w;
            x = max(h, w), y = min(h, w), t = max(min(2 * x, 2 * y), min(4 * y, x));
            if (t > v) ans = i + 1, v = t;
        }
        cout << ans << endl;
    }
    return 0;
}
