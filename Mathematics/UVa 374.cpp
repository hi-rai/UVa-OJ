//Easy implementation using modular arithematic

#include<bits/stdc++.h>
using namespace std;

long long ans, t, B, P, M;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> B >> P >> M) {
        t = B, ans = 1;
        while (P) {
            if (P & 1) ans *= t, ans %= M;
            t *= t, t %= M, P /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
