//An easy problem of finding the intersection point of two lines

#include<bits/stdc++.h>
#define epsilon 1e-9
using namespace std;

typedef double T;
T l, theta;
const double PI = acos(-1);

struct pt {
    T x, y;
    pt(T a, T b) : x(a), y(b) {}
    pt() : x(0), y(0) {}
    pt operator+ (pt p) { return { x + p.x, y + p.y}; }
    pt operator- (pt p) { return { x - p.x, y - p.y}; }
    pt operator* (T k) { return { k * x, k * y }; }
    pt operator/ (T k) { return { x / k, y / k }; }
    bool operator== (pt p) { return (abs(x - p.x) < epsilon && abs(y - p.y) < epsilon);}
    bool operator!= (pt p) { return (abs(x - p.x) >= epsilon || abs(y - p.y) >= epsilon);}
};

T cross(pt p, pt q) { return p.x * q.y - p.y * q.x; }
double abs(pt p) { return sqrt(p.x * p.x + p.y * p.y); }
pt perp(pt p) { return pt{-p.y, p.x}; }
pt rotate(pt c, double a, pt p) { return c + pt{(p.x - c.x) * cos(a) - (p.y - c.y) * sin(a), (p.x - c.x) * sin(a) + (p.y - c.y) * cos(a)}; }
ostream& operator<< (ostream& os, pt p) {return os << "(" << p.x << "," << p.y << ")"; }

struct line {
    pt v; T c;
    line(pt a, pt b) : v(b - a), c(cross(v, b)) {}
};

bool inter(line l1, line l2, pt& p) {
    double t = cross(l1.v, l2.v);
    if(!t)  return false;
    p = (l2.v * l1.c - l1.v * l2.c) / t;
    return true;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> l) {
        cout<<fixed<<setprecision(10);
        theta = ((double)36.0) / 180.0 * PI;
        pt a(-l / 2, 0), d;
        pt b = rotate(a, PI - 2 * theta, pt(l / 2, 0));
        pt c = rotate(b, theta, pt(l + b.x, b.y));
        inter(line(a, b), line(c, perp(c)), d);
        cout << fixed << setprecision(10) << abs(c - d) << endl;
    }
    return 0;
}
