//Not that difficult problem.
//Think of different axis independently while calculating the intersection regions

#include<bits/stdc++.h>
using namespace std;

int x, y, z, dx, dy, dz, a, b, c, da, db, dc, ans;
int t, u, v, dt, du, dv, n;
bool calc(int x1, int l1, int x2, int l2, int& x, int& dx) {
    if (x1 <= x2) {
        if (x1 + l1 <= x2) return false;
        x = x2, dx = min(x1 + l1 - x2, l2);
        return true;
    } else {
        if (x2 + l2 <= x1) return false;
        x = x1, dx = min(x2 + l2 - x1, l1);
        return true;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n) {
        ans = 1;
        cin >> x >> y >> z >> dx, dz = dy = dx;
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b >> c >> da, db = dc = da;
            if (calc(x, dx, a, da, t, dt) && calc(y, dy, b, db, u, du) && calc(z, dz, c, dc, v, dv))
                x = t, y = u, z = v, dx = dt, dy = du, dz = dv;
            else ans = 0;
        }
        ans *= dx * dy * dz;
        cout << ans << endl;
    }
    return 0;
}
