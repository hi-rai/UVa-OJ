//Starting with their first character match the characters of s with the next character of t which is same.

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s, t;
    while (cin >> s >> t) {
        int ans = 0;
        for (int i = 0, j = 0, m = s.length(), n = t.length(); i < m; i++, j++) {
            while (j < n && s[i] != t[j]) j++;
            if (j == n) break;
            if (i == m - 1) ans = 1;
        }
        if (ans) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
