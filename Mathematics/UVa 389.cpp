#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int a, b;
    char ans[8];
    while (cin >> s >> a >> b) {
        int x = 0, m = 1, ind = 6;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] <= '9' && s[i] >= '0')
                x += m * (int) (s[i] - '0'), m *= a;
            else x += m * ((int) (s[i] - 'A') + 10), m *= a;
        }
        memset(ans, ' ', sizeof ans);
        ans[7] = '\0', ans[6] = '0';
        while (x) {
            if (ind < 0) break;
            int t = x % b;
            x /= b;
            if (t > 9) ans[ind--] = ('A' + t - 10);
            else ans[ind--] = ('0' + t);
        }
        if (x) cout << "  ERROR\n";
        else cout << ans << "\n";
    }
    return 0;
}
