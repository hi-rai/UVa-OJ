//Because of the high time limit in the question, its OK to use brute force. Just take care of the number of zeroes, while taking
//mod inside the for loop, lower values may lead to WA

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long m, n;
    while (cin >> n >> m) {
        long long ans = 1;
        for (long long i = n - m + 1; i <= n; i++) {
            ans *= i;
            while (ans % 10 == 0) ans /= 10;
            ans %= 100000000000;
        }
        cout << ans % 10 << endl;
    }
    return 0;
}
