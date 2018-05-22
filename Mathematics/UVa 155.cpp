//An easy problem

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, ans;
    int a, b;
    while (cin >> a >> b >> s) {
        long long x = 0, m = 1, t, ch = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] <= '9' && s[i] >= '0')
                x += m * (t = (int) (s[i] - '0')), m *= a;
            else x += m * (t = ((int) (s[i] - 'A') + 10)), m *= a;
            if (t >= a) ch = 0;
        }
        if (!ch) {
            cout << s << " is an illegal base " << a << " number\n";
            continue;
        }
        ans = "";
        while (x) {
            int t = x % b;
            x /= b;
            if (t > 9) ans += ('A' + t - 10);
            else ans += ('0' + t);
        }
        cout << s << " base " << a << " = ";
        if (ans == "") cout << 0;
        else {
            reverse(ans.begin(), ans.end());
            cout << ans;
        }
        cout << " base " << b << "\n";
    }
    return 0;
}
