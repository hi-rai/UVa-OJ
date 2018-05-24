//An easy problem

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t, cnt, inc, inccnt, deccnt, incind, decind;
    while (cin >> n, n) {
        cnt = inc = decind = deccnt = incind = inccnt = 0;
        while (cin >> t, t) {
            if (inc == 0) {
                if (t == n) cnt++;
                else if (t > n) incind++, inccnt += cnt + 1, cnt = 0, inc = 1;
                else if (t < n) decind++, deccnt += cnt + 1, cnt = 0, inc = -1;
            } else if (inc == 1) {
                if (n <= t) inccnt++;
                else inc = -1, deccnt++, decind++;
            } else {
                if (n >= t) deccnt++;
                else inc = 1, inccnt++, incind++;
            }
            n = t;
        }
        cout << "Nr values = " << cnt + deccnt + inccnt + 1 << ":  " << fixed << setprecision(6)
             << (incind ? inccnt / (double) incind : 0.0)
             << " " << (decind ? deccnt / (double) decind : 0.0) << endl;
    }
    return 0;
}
