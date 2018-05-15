//An easy problem of finding the intersection point of two lines

#include<bits/stdc++.h>
#define epsilon 1e-9
using namespace std;

typedef double T;
int n;

struct pt {
    T x, y;
    pt operator+ (pt p) { return { x + p.x, y + p.y}; }
    pt operator- (pt p) { return { x - p.x, y - p.y}; }
    pt operator* (T k) { return { k * x, k * y }; }
    pt operator/ (T k) { return { x / k, y / k }; }
    bool operator== (pt p) { return (abs(x - p.x) < epsilon && abs(y - p.y) < epsilon);}
    bool operator!= (pt p) { return (abs(x - p.x) >= epsilon || abs(y - p.y) >= epsilon);}
}a, b, c, d, p;
ostream& operator<< (ostream& os, pt p) {return os << "(" << p.x << "," << p.y << ")"; }
T cross(pt p, pt q) { return p.x * q.y - p.y * q.x; }

struct line {
    pt v; T c;
    line(pt a, pt b) : v(b - a), c(cross(v, b)) {}
};

double side(line l, pt p) { return cross(l.v, p) - l.c; }

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
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    cout << fixed << setprecision(2);
    while (n--) {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        if (inter(line(a, b), line(c, d), p)) cout << "POINT " << p.x << " " << p.y << endl;
        else if (abs(side(line(a, b), c)) < epsilon) cout << "LINE" << endl;
        else cout << "NONE" << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
