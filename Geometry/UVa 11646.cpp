//Use divide and conquer, binary search technique to find the valid solution from the range (0, 400.0 / max(a, b)).

#include<bits/stdc++.h>
#define eps 1e-9
using namespace std;

double a, b, m;
int tc = 1; char c;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> a, !cin.eof()) {
        cin >> c >> b;
        double t = 0, u = 400.0 / max(a, b);
        for (int i = 0; i < 40; i++) {
            m = (t + u) / 2;
            double z = sqrt(m * m * a * a + m * m * b * b), v = 2 * z * asin(m * b / z) + 2 * m * a;
            if (abs(v - 400.0) < eps) break;
            else if (v > 400.0) u = m;
            else t = m;
        }
        cout << "Case " << tc++ << ": " << fixed << setprecision(10) << m * a << " " << m * b << endl;
    }
    return 0;
}
