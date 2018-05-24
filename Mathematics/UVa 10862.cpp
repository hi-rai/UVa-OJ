//We will have to maintain two numbers, one is the answer for each possible n and the other is the sum of answers from 1 to n plus 1.
//And if ans(n) denotes the answer for n, and sum(n) denotes ans(0) + ans(1) + ans(2) + ...... + ans(n), then ans(n+1) = ans(n) + sum(n)
//To see this for ans(n+1), ans(n) denotes the number of ways the (n+1)th house can receive connection from the house to its left.
//Now, a direct connection for house (n+1) can be used to provide connections to 0, 1, 2, 3, 4, .... , n houses on its immediate 
//left and in each of these cases the remaining n, (n-1), (n-2), ..... , 2, 1, 0 houses can be connected by ans(n), ans(n-1), 
//ans(n-2), .... , ans(2), ans(1), ans(0) ways. Now to find the total its good if we maintain sum(n). Now, ans(0) makes no sense but
//we define it as 1 to work our way through the base case.

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans[2005][1005], sum[1005], n;
    memset(ans, 0, sizeof ans);
    memset(sum, 0, sizeof sum);
    ans[1][0] = 1, sum[0] = 2;
    for (int i = 2; i <= 2000; i++)
        for (int j = 0, sc = 0, ac = 0; j < 1000; j++) {
            ans[i][j] = sum[j] + ans[i - 1][j] + ac;
            ac = ans[i][j] / 10, ans[i][j] %= 10;
            sum[j] += ans[i][j] + sc;
            sc = sum[j] / 10, sum[j] %= 10;
        }
    while (cin >> n, n) {
        int ind = 1004;
        while (!ans[n][ind] && ind >= 0) ind--;
        while (ind >= 0) cout << ans[n][ind--];
        cout << endl;
    }
    return 0;
}
