//Eihter use the DP solution or use the following direct formula.
//The formula can be worked out as follow
// Sum from i = 1 to less than (n - 1)/2  (which for even numbers is (n - 2)/2 and for the odd numbers is (n - 3)/2
//    Sum from j = (i + 1) to (n - i - 1) (ie. till (n - i - j) > 0 is satisfied)
//        (n - i - j)

#include<bits/stdc++.h>
using namespace std;

long long n = 10;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n, n >= 3) {
        if (n & 1)
            cout << ((n - 1) * (n - 3) * (2 * n - 1)) / 24 << endl;
        else cout << (n * (2 * n - 5) * (n - 2)) / 24 << endl;
    }
    return 0;
}
