#include<bits/stdc++.h>
#define SZ 30
#define INF 10000
using namespace std;

int arr[SZ][SZ], TC;
char str[50], ch;

int MaxSum2D(int r, int c) {
    int ans = 0, temp[SZ][SZ], sum = 0;
    memset(temp, 0, sizeof temp);
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            temp[i][j] = temp[i - 1][j] + arr[i][j];
    for (int i = 1; i <= r; i++)
        for (int j = i; j <= r; j++) {
            sum = 0;
            for (int k = 1; k <= c; k++) {
                sum += (temp[j][k] - temp[i - 1][k]);
                ans = max(ans, sum);
                sum = max(0, sum);
            }
        }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &TC);
    getchar(), getchar();
    while (TC--) {
        int r = 0, c = 0;
        while (fgets(str, 50, stdin) != NULL && strlen(str) > 1) {
            r++, c = 0;
            while (sscanf(str + c, "%c", &ch) == 1 && ch != '\n')
                c++, arr[r][c] = (ch == '1' ? 1 : -INF);
        }
        printf("%d\n", MaxSum2D(r, c));
        if(TC) printf("\n");
    }
    return 0;
}
