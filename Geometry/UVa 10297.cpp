//Directly based on formula

#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
int V, D;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> D >> V, D)
        cout << fixed << setprecision(3) << pow(pow(D, 3) - 6.0 * V / PI, 1.0 / 3.0) << endl;
    return 0;
}
