//An easy problem

#include<bits/stdc++.h>
#define PI 3.141592653589793
#define R  6371009LL
using namespace std;

struct pt {
    double x, y, z;
    pt() : x(0), y(0), z(0) {}
    pt(double x, double y, double z) : x(x), y(y), z(z) {}
    pt(double t, double u) : x(R * cos(PI * t / 180) * cos(PI * u / 180)), y(R * cos(PI * t / 180) * sin(PI * u / 180)),
                             z(R * sin(PI * t / 180)) {}
    pt operator+(pt p) { return {x + p.x, y + p.y, z + p.z}; }
    pt operator-(pt p) { return {x - p.x, y - p.y, z - p.z}; }
    pt operator*(double t) { return {x * t, y * t, z * t}; }
    pt operator/(double t) { return {x / t, y / t, z / t}; }
};

double abs(pt p) { return sqrt(p.x * p.x + p.y * p.y + p.z * p.z); }

pt a, b;
double u, t;
int n;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> t >> u, a = pt(t, u);
        cin >> t >> u, b = pt(t,u);
        double d1 = abs(a - b);
        double d2 = 2.0 * R * asin(abs(d1 / 2.0 / R));
        cout << fixed << setprecision(0) << d2 - d1 << endl;
    }
    return 0;
}
