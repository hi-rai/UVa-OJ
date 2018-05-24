#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long A, L, cnt, B, tc = 1;
    while (cin >> A >> L, A > 0) {
        cnt = 0, B = A;
        while (A <= L && A != 1) {
            cnt++;
            if (A & 1) A = 3 * A + 1;
            else A /= 2;
        }
        cout << "Case " << tc++ << ": A = " << B << ", limit = " << L << ", number of terms = ";
        cout << (A == 1 ? cnt + 1 : cnt) << endl;
    }
    return 0;
}
