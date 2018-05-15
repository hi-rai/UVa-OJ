//A very easy problem

#include<bits/stdc++.h>
using namespace std;

double lx[0], ly[10], rx[10], ry[10], x, y;
int n = 0, check = 0, m = 0;
char r;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> r, r == 'r')
        cin >> lx[n] >> ly[n] >> rx[n] >> ry[n], n++;
    while (cin >> x >> y, x != 9999.9 || y != 9999.9) {
        m++, check = 0;
        for (int i = 0; i < n; i++) {
            if (x > lx[i] && x < rx[i] && y > ry[i] && y < ly[i])
                check = 1, cout << "Point " << m << " is contained in figure " << i + 1 << endl;
        }
        if (!check) cout << "Point " << m << " is not contained in any figure" << endl;
    }
    return 0;
}
