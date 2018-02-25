//An easy AdHoc problem

#include<bits/stdc++.h>
using namespace std;

int H, U, D, F;
float u, y, f, toClimb;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> H >> U >> D >> F, cin && H) {
        u = U, f = (u * F) / 100, y = 0;
        int day = 1;
        while (1) {
            toClimb = (u > 0 ? u : 0);
            y += toClimb;
            if (y > H) {
                cout << "success on day " << day << endl;
                break;
            }
            y -= D;
            if (y < 0) {
                cout << "failure on day " << day << endl;
                break;
            }
            day++, u -= f;
        }
    }
    return 0;
}
