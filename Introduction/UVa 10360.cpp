#include<bits/stdc++.h>
using namespace std;

int TC, d, n, tot, x, y, z, ansx, ansy;
int killed[1025][1025];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        memset(killed, 0, sizeof killed);
        cin >> d >> n;
        tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            int t = min(1024, x + d), u = min(1024, y + d);
            for (int l = max(0, x - d); l <= t; l++)
                for (int m = max(0, y - d); m <= u; m++)
                    if ((killed[l][m] += z) > tot)
                        tot = killed[l][m], ansx = l, ansy = m;
                    else if (killed[l][m] == tot) {
                        if (l < ansx)
                            ansx = l, ansy = m;
                        else if (l == ansx && m < ansy)
                            ansx = l, ansy = m;
                    }
        }
        cout << ansx << " " << ansy << " " << tot << endl;
    }
    return 0;
}
