//Consider the case when light is going downward for that let the number of possible light rays reflected from the upper boundary 
//be denoted by l, and from the middle boundary by u. Similarly for a light ray going upward, let the light ray being reflected
//from the lower boundary be called l and middle boundary be called u. Let the number of reflections be k.
//So, we find that l(k+1) = l(k) + u(k) and u(k+1) = l(k). This also means that u(k) = l(k - 1), which implies total light rays are
//l(k+1) = l(k) + l(k-1). And, also total light rays after k reflections is l(k) + u(k) = l(k+1). So, we need to keep track of only
//l(k), which forms a fibonacci type sequence, but we still have to work out the base conditions. This can be done manually and we
//arrive at the sequence 1,2,3,5,8,11........ 

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int dp[1005][220], n;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1, dp[1][0] = 2;
    for (int i = 2; i < 1001; i++)
        for (int j = 0, c = 0; j < 220; j++) {
            dp[i][j] = dp[i - 2][j] + dp[i - 1][j] + c;
            c = dp[i][j] / 10, dp[i][j] %= 10;
        }
    while (cin >> n) {
        int ind = 219;
        while (!dp[n][ind]) ind--;
        while (ind >= 0) cout << dp[n][ind--];
        cout << endl;
    }
    return 0;
}
