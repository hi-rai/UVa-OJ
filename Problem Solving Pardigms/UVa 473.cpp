#include<bits/stdc++.h>
using namespace std;

int TC, arr[10005], n, t, m;
vector<vector<int> > memo;

int calc(int x, int y) {
    if(x >= n || y == 0) return 0;
    if(memo[x][y] != -1) return memo[x][y];
    int ans = calc(x + 1, y), p = (y % t);
    if(p < arr[x] && p != 0) ans = max(ans, calc(x, y - p));
    else ans = max(ans, calc(x + 1, y - arr[x]) + 1);
    return memo[x][y] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d %d", &n, &t, &m);
        for (int i = 0; i < n; i++)
            scanf(" %d ,", arr + i);
        memo.assign(n + 5, vector<int>(t * m + 5, -1));
        printf("%d\n", calc(0, t * m));
        if (TC) printf("\n");
    }
    return 0;
}
