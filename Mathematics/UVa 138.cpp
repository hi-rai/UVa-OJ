#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long cnt = 0, n = 2;
    while (cnt < 10) {
        long long t = n * (n + 1) / 2, a = sqrt(t);
        if (a * a == t) cout << setw(10) << a << setw(10) << n << endl, cnt++;
        n++;
    }
    return 0;
}
