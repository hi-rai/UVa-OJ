//Easy problem. For each base, check whether the number assumed in that base converted to decimal is a perfect square

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (cin >> s, s[0] != '0') {
        int b = 1, done = 0;
        for (int i = 0, n = s.length(); i < n; i++) b = max(b, (int) (s[i] - '0'));
        for (int i = (++b); i < 100 && !done; i++) {
            int x = 0, t = 1;
            for (int j = s.length() - 1; j >= 0; j--)
                x += t * (int) (s[j] - '0'), t *= i;
            t = (int) sqrt(x);
            if (t * t == x) {
                cout << i << "\n";
                done = 1;
            }
        }
    }
    return 0;
}
