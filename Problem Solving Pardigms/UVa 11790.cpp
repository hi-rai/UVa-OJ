#include<bits/stdc++.h>
using namespace std;

vector<int> h, w, inc, decr;
int TC, n, ansi, ansd, tc = 1;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> n;
        h.resize(n), w.resize(n), inc.resize(n), decr.resize(n);
        for (int i = 0; i < n; i++) cin >> h[i];
        for (int i = 0; i < n; i++) cin >> w[i];
        ansi = ansd = decr[0] = inc[0] = w[0];
        for (int i = 1; i < n; i++) {
            inc[i] = 0, decr[i] = 0;
            for (int j = 0; j < i; j++) {
                if (h[i] > h[j]) inc[i] = max(inc[i], inc[j]);
                else if (h[i] < h[j]) decr[i] = max(decr[i], decr[j]);
            }
            inc[i] += w[i], decr[i] += w[i];
            ansi = max(ansi, inc[i]), ansd = max(ansd, decr[i]);
        }
        if (ansi >= ansd)
            cout << "Case " << tc++ << ". Increasing (" << ansi << "). Decreasing (" << ansd << ")." << endl;
        else cout << "Case " << tc++ << ". Decreasing (" << ansd << "). Increasing (" << ansi << ")." << endl;
    }
    return 0;
}
