#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    long long memo[6005], coins[] = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};
    double v;
    memset(memo, 0, sizeof memo), memo[0] = 1;
    for(auto i : coins)
        for(int j = 0; j < 6005; j++)
            if(j + i < 6005)
                memo[j + i] += memo[j];
    while (cin >> v, v > 1e-4) {
        int t = (int)(ceil(v * 100)) / 5;
        cout << setw(6) << fixed << setprecision(2) << v << setw(17) << memo[t] << endl;
    }
}
