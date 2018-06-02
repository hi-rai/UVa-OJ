#include<bits/stdc++.h>
#define SZ 10005
using namespace std;

long long memo[SZ][100], coins[100], n = 25, V;

long long calc(int v, int k) {
    if(v < 0 || k >= n) return 0;
    if(v == 0) return 1;
    if(memo[v][k] != -1) return memo[v][k];
    memo[v][k] = calc(v, k + 1) + calc(v - coins[k], k);
    return memo[v][k];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for(int i = 1; i <= 25; i++)
        coins[i - 1] = i * i * i;
    memset(memo, -1, sizeof memo);
    while(cin >> V) cout << calc(V, 0) << endl;
    return 0;
}
