//Easy problem, take care that for integer divisions, ab / cd is not equal to a/c * b/d

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m, c;
    while (cin >> n >> m >> c, n) {
        if (c) cout << ((n - 6) / 2) * ((m - 6) / 2) + ((n - 7)/2) * ((m - 7) / 2) << endl;
        else cout << ((n - 7)/2) * ((m - 6) / 2) + ((n - 8)/2) * ((m - 7) / 2) + (m - 7) / 2 << endl;
    }
    return 0;
}
