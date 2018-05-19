//A difficult problem.
//The problem can be reduced to finding whether the sum of integral multiples of certain 2D vectors can be made zero.
//This problem can be solved by checking whether the origin lies inside the convex hull formed by these vectors.
//Now this problem itself can be solved by checking the angle between any two consecutive vectors (consecutive according to angle 
//made from x-axis) is less than 180 degrees.

#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1);
double d, theta[1005];
int t, u, v, n;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n) {
        d = 0;
        for (int i = 0; i < n; i++)
            cin >> t >> u >> v, theta[i] = atan2(t - v, u - v);
        sort(theta, theta + n);
        for (int i = 1; i < n; i++) d = max(d, theta[i] - theta[i - 1]);
        d = max(d, 2 * PI - theta[n - 1] + theta[0]);
        if (d > PI) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}
