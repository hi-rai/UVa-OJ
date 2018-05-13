//can be solved by considering all the possible permutations, because of small input
//take care of avoiding overlaps and possible overflow outside the considered rectangle, at both the ends

#include<bits/stdc++.h>
using namespace std;

double r[10], ans, pos[10], scorr, ecorr;
int n, m;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> m, ans = 0;
        for (int i = 0; i < m; i++)
            cin >> r[i], ans += 2 * r[i];
        sort(r, r + m);
        do {
            pos[0] = r[0], ecorr = scorr = 0;
            for (int i = 1; i < m; i++) {
                double temp = -1;
                for (int j = 0; j < i; j++)
                    temp = max(temp, pos[j] + sqrt(4 * r[i] * r[j]));
                pos[i] = temp;
            }
            for (int i = 0; i < m; i++)
                scorr = max(scorr, r[i] - pos[i]),
                        ecorr = max(ecorr, r[i] + pos[i] - pos[m - 1] - r[m - 1]);
            ans = min(ans, pos[m - 1] + r[m - 1] + scorr + ecorr);
        } while (next_permutation(r, r + m));
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}
