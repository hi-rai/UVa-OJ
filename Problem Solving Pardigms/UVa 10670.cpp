#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC, N, M, L, tc = 1, a, b, c[1005], ind;
    char str[1005][25];
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d %d", &N, &M, &L);
        ind = 0;
        while(L--) {
            scanf(" %[^:]:%d,%d", str[ind], &b, &a);
            int cost = 0, n = N;
            while((n - (n + 1) / 2) >= M && a < (n + 1) / 2 * b) cost += a, n -= (n + 1) / 2;
            cost += (n - M) * b;
            c[ind++] = cost;
        }
        int od[ind];
        for(int i = 0; i < ind; i++) od[i] = i;
        sort(od, od + ind, [&](int x, int y) {
            if(c[x] == c[y])    return strcmp(str[x], str[y]) < 0;
            return c[x] < c[y];
        });
        printf("Case %d\n", tc++);
        for(int i = 0; i < ind; i++)
            printf("%s %d\n", str[od[i]], c[od[i]]);
    }
    return 0;
}
