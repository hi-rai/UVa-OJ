//Think of the ball moving in a straight line instead of bouncing off a wall (think of infinitely arranged billiard boards
//stacked next to each other and the ball moves from one board to the other instead of bouncing off a wall

#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
double a, b, m, n, s;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> a >> b >> s >> m >> n, a) {
        double t = a * m, u = b * n;
        cout << fixed << setprecision(2) << atan(u / t) * 180 / PI << " " << sqrt(u * u + t * t) / s << endl;
    }
    return 0;
}
