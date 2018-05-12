//An easy problem of finding maximum number of collinear points

#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;

int TC, ans, n, tc = 1, gnus;
set<pair<double, double> > p;
double t, u, q[200];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> n, p.clear(), ans = INT_MIN;
        for (int i = 0; i < n; i++)
            cin >> t >> u, p.insert({t, u});
        for (auto it = p.begin(); it != p.end(); it++) {
            int cnt = 0, tot = 2;
            auto jt = (++it)--;
            for (; jt != p.end(); jt++, cnt++) {
                if (((*jt).first - (*it).first) < EPS) q[cnt] = FLT_MAX;
                else q[cnt] = ((*jt).second - (*it).second) / ((*jt).first - (*it).first);
            }
            sort(q, q + cnt);
            for (int j = 1; j < cnt; j++) {
                if (abs(q[j] - q[j - 1]) < EPS) tot++;
                else ans = max(ans, tot), tot = 2;
            }
            ans = max(ans, tot);
        }
        gnus = distance(p.begin(), p.end());
        if (gnus == 1) cout << "Data set #" << tc++ << " contains a single gnu." << endl;
        else
            cout << "Data set #" << tc++ << " contains " << gnus << " gnus, out of which a maximum of " << ans
                 << " are aligned." << endl;
    }
    return 0;
}
