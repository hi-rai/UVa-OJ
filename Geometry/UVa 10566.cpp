//Use divide and conquer, binary search technique to calculate the required value from possible solution set of (0, min(x, y)).

#include<bits/stdc++.h>
#define eps 1e-9
using namespace std;

double x, y, c;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> x >> y >> c, !cin.eof()) {
        double l = 0, h = min(x, y);
        for (int i = 0; i < 30; i++) {
            double m = (l + h) / 2, a = sqrt(y * y - m * m), b = sqrt(x * x - m * m), v = a * b / (a + b);
            if (abs(v - c) < eps) break;
            else if (v < c) h = m;
            else l = m;
        }
        cout << fixed << setprecision(3) << (l + h) / 2 << endl;
    }
    return 0;
}
