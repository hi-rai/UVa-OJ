//An easy problem

#include<bits/stdc++.h>
using namespace std;

double A, r, R, Ai, Ae;
const double PI = 2 * acos(0);
int n, tc = 1;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n > 2) {
        cin >> A;
        R = sqrt(2 * A / n / sin(2 * PI / n));
        r = R * cos(PI / n);
        Ai = PI * r * r;
        Ae = PI * R * R;
        cout << fixed << setprecision(5) << "Case " << tc++ << ": " << Ae - A << " " << A - Ai << endl;
    }
    return 0;
}
