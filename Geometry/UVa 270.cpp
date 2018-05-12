//First sort the points. This ensures an easy implementation of the further O(N^2) algorithm.
//Through each point, find the maximum number of lines that are collinear in the sorted order

#include<bits/stdc++.h>
using namespace std;

int TC, ans, t, u, n;
string s;
pair<int, int> p[705], q[705];

int GCD(int x, int y) {
    return y == 0 ? x : GCD(y, x % y);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    cin.ignore().ignore();
    while (TC--) {
        ans = 2, n = 0;
        while (getline(cin, s), !cin.eof() && s.length()) {
            stringstream in;
            in << s;
            in >> t >> u;
            p[n++] = {t, u};
        }
        sort(p, p + n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                q[j] = {p[j].second - p[i].second, p[j].first - p[i].first};
                int gcd = GCD(max(abs(q[j].first), abs(q[j].second)), min(abs(q[j].first), abs(q[j].second)));
                q[j].first /= gcd, q[j].second /= gcd;
            }
            sort(q + i + 1, q + n);
            int cnt = 2;
            for (int j = i + 2; j < n; j++) {
                if (q[j] == q[j - 1]) cnt++;
                else ans = max(ans, cnt), cnt = 2;
            }
            ans = max(ans, cnt);
        }
        cout << (n == 1 ? 1 : ans) << endl;
        if (TC) cout << endl;
    }
    return 0;
}
