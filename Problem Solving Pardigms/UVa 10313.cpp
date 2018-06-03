//Using bottom-up DP
#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long memo[305][305], a, b, c, ans;
    char str[50];
    memset(memo, 0, sizeof memo), memo[0][0] = 1;
    for (int i = 1; i <= 300; i++)
        for (int j = 300; j >= 0; j--)
            for (int k = 300; k >= 0; k--)
                for (int l = (300 - j) / i; l > 0; l--)
                    memo[j + i * l][k + l] += memo[j][k];
    while (fgets(str, 50, stdin) != NULL) {
        int t = sscanf(str, "%lld %lld %lld", &a, &b, &c);
        ans = 0;
        if (t == 1) {
            for (int i = 0, k = min(300LL, a); i <= k; i++)
                ans += memo[a][i];
        } else if (t == 2) {
            for (int i = 0, k = min(300LL, b); i <= k; i++)
                ans += memo[a][i];
        } else {
            for (int i = b, k = min(300LL, c); i <= k; i++)
                ans += memo[a][i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}

//Using top-down DP (much slower than bottom up version)
/*
#include<bits/stdc++.h>
using namespace std;

long long memo[305][305][305], ans;
int a, b, c;
char str[50];

long long calc(int val, int k, int c) {
    if(val == 0 && k == 0) return 1;
    if(val <= 0 || c > 300) return 0;
    if(memo[val][k][c] != -1) return memo[val][k][c];
    long long temp = 0;
    for(int i = 0; i * c <= val && i <= k; i++)
        temp += calc(val - c * i, k - i, c + 1);
    return memo[val][k][c] = temp;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(memo, -1, sizeof memo);
    while (fgets(str, 50, stdin) != NULL) {
        int t = sscanf(str, "%d %d %d", &a, &b, &c);
        ans = 0;
        if (t == 1) {
            for (int i = 0, k = min(300, a); i <= k; i++)
                ans += calc(a, i, 1);
        } else if (t == 2) {
            for (int i = 0, k = min(300, b); i <= k; i++)
                ans += calc(a, i, 1);
        } else {
            for (int i = b, k = min(300, c); i <= k; i++)
                ans += calc(a, i, 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}*/
