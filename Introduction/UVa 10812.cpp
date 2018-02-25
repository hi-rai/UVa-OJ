#include<bits/stdc++.h>
using namespace std;

long long x,y;
int TC;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> x >> y;
        if (y > x || (x + y) % 2)
            cout << "impossible" << endl;
        else
            cout << (x + y) / 2 << " " << (x - y) / 2 << endl;
    }
    return 0;
}
