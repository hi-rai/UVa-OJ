//Easy problem, just think of the boards to extend to infinity and the ball to continue along a straight line instead of bouncing back

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double a, b, v, A, s, theta, x, y;
    while (cin >> a >> b >> v >> A >> s, a) {
        theta = A * (3.14159265) / 180;
        x = a / 2 + v * s * cos(theta) / 2;
        y = b / 2 + v * s * sin(theta) / 2;
        cout << (int) (x / a) << " " << (int) (y / b) << endl;
    }
    return 0;
}
