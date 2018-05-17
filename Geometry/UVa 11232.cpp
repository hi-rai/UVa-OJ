//A bit of calculus can ease the task

#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
double w, h;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> w >> h, w) {
        double v1 = PI * w * pow(min(h / (PI + 1), w), 2.0) / 4;
        double d = w / PI, v2 = PI * d * d * (h - d) / 4;
        cout << fixed << setprecision(3) << max(v1, v2) << endl;
    }
    return 0;
}
