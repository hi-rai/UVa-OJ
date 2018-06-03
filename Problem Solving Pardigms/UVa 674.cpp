//Using bottom-up DP
#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int memo[8000], n, coins[] = {1, 5, 10, 25, 50};
    memset(memo, 0,sizeof memo), memo[0] = 1;
    for(auto i : coins)
        for(int j = 0; j < 8000; j++)
            if(i + j < 8000) memo[i + j] += memo[j];
    while(cin >> n) cout << memo[n] << endl;
    return 0;
}

//Using top-down DP
/*
#include<bits/stdc++.h>
using namespace std;

int memo[8000][5], n, coins[] = {1, 5, 10, 25, 50};

int calc(int val, int k) {
    if(val == 0) return 1;
    if(val < 0 || k > 4) return 0;
    if(memo[val][k] != -1) return memo[val][k];
    int temp = 0;
    for(int i = 0; coins[k] * i <= val; i++)
        temp += calc(val - i * coins[k], k + 1);
    return memo[val][k] = temp;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    memset(memo, -1,sizeof memo);
    while(cin >> n) cout << calc(n, 0) << endl;
    return 0;
}*/
