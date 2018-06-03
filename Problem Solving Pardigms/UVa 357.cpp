#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    long long memo[30005], coins[] = {1, 5, 10, 25, 50}, n;
    memset(memo, 0, sizeof memo), memo[0] = 1;
    for(auto i : coins)
        for(int j = 0; j < 30005; j++)
            if(j + i < 30005)
                memo[j + i] += memo[j];
    while(cin >> n) {
        if(memo[n] == 1) cout << "There is only 1 way to produce "<< n << " cents change.\n";
        else cout << "There are " << memo[n] << " ways to produce " << n << " cents change.\n";
    }
    return 0;
}
