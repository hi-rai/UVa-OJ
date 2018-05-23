//An easy problem of modular arithmatic

#include<bits/stdc++.h>
#define MOD 131071
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int ans = 0;
        char x;
        if(cin >> x, cin.eof()) break;
        while (x != '#')
            ans = (ans * 2) % MOD + (x == '1'), cin >> x;
        ans %= MOD;
        if (ans) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
