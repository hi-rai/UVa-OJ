#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int memo[4010], coins[] = {1, 2, 4, 10, 20, 40};
    double v;
    for (auto &i : memo) i = INF;
    memo[0] = 0;
    for (int i = 0; i < 4005; i++)
        if (memo[i] != INF)
            for (auto j : coins)
                if (i + j <= 4005)
                    memo[i + j] = min(memo[i + j], memo[i] + 1);
    while (true) {
        int t, p[4010], x, val, ans = INF, check = 0;
        for (auto &i : p) i = INF;
        p[0] = 0;
        for (auto i : coins) {
            cin >> t;
            check |= t;
            for (int j = 4005; j >= 0; j--)
                if (p[j] != INF)
                    for (int k = 1; k <= t; k++)
                        if (x = j + k * i, x <= 4005)
                            p[x] = min(p[x], p[j] + k);
        }
        cin >> v;
        val = ((int) ceil(v * 100.0)) / 5;
        if (!check) return 0;
        for (int i = val; i <= 4005; i++)
            ans = min(ans, p[i] + memo[i - val]);
        cout << setw(3) << ans << endl;
    }
}
