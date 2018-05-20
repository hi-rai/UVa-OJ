#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans[25], chk = 0;
    memset(ans, 0, sizeof ans);
    ans[0] = ans[2] = 1;
    for (int i = 4; i <= 20; i += 2) {
        for (int j = 0; j <= i - 2; j += 2)
            ans[i] += ans[j] * ans[i - j - 2];
    }
    while (cin >> n) {
        if (chk == 0) chk = 1;
        else cout << "\n";
        cout << ans[2 * n] << "\n";
    }
    return 0;
}
