//An easy problem of finding whether a polygon is convex or not. Can be found by calculating the signs of the cross products
//of consecutive sides of the polygon. If they have the same sign, then the polygon is convex, otherwise it is concave

#include<bits/stdc++.h>
using namespace std;

int n, x[55], y[55], ans, t;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n) {
        ans = 1;
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        x[n] = x[0], y[n] = y[0];
        t = (x[n - 1] - x[0]) * (y[1] - y[0]) - (x[1] - x[0]) * (y[n - 1] - y[0]), t /= abs(t);
        for (int i = 1; i < n && ans; i++)
            if (((x[i - 1] - x[i]) * (y[i + 1] - y[i]) - (x[i + 1] - x[i]) * (y[i - 1] - y[i])) * t < 0)
                ans = 0;
        if (ans) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
