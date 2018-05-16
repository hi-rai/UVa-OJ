//An easy problem of spherical coordinates

#include<bits/stdc++.h>
#define R 6378
using namespace std;

const double PI = acos(-1);
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
ostream& operator<< (ostream& os, pt p) {return os << "(" << p.x << "," << p.y << "," << p.z << ")"; }

map<string, int> ind;
pt p[105];
string s, t;
double u, v;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0;
    while (cin >> s, s != "#")
        ind[s] = n++, cin >> u >> v, p[ind[s]] = pt(u, v);
    while (cin >> s >> t, s != "#") {
        cout << s << " - " << t << endl;
        if(ind.count(s) && ind.count(t))
            cout << fixed << setprecision(0) << 2 * R * asin(abs(p[ind[s]] - p[ind[t]]) / 2 / R) << " km" << endl;
        else cout << "Unknown" << endl;
    }
    return 0;
}
