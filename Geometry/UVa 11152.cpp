//A very easy problem, a direct application of formula

#include<bits/stdc++.h>
using namespace std;

double a, b, c, r, R, A, s;
const double PI = acos(-1);

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> a >> b >> c) {
        s = (a + b + c) / 2;
        A = sqrt(s * (s - a) * (s - b) * (s - c));
        r = A / s, r = PI * r * r;
        R = (a * b * c) / (4 * A), R = PI * R * R;
        cout << fixed << setprecision(4) << R - A << " " << A - r << " " << r << endl;
    }
    return 0;
}
