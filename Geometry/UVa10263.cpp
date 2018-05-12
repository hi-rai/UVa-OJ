//Basic problem of finding the nearest point on a line segment from an external point

#include<bits/stdc++.h>
#define epsilon 1e-9
using namespace std;

typedef double T;
T x, y, ansAbs, t, u;
int n;

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
}ans, temp, M;

double abs(pt p) { return sqrt(p.x * p.x + p.y * p.y); }
double _norm_(pt p) {return p.x * p.x + p.y * p.y; }
T dot(pt p, pt q) { return p.x * q.x + p.y * q.y; }
T cross(pt p, pt q) { return p.x * q.y - p.y * q.x; }
pt perp(pt p) { return pt{-p.y, p.x}; }

struct line {
    pt v; T c;
    line(pt a, pt b) : v(b - a), c(cross(v, b)) {}
};

double side(line l, pt p) { return cross(l.v, p) - l.c; }
pt proj(line l, pt p) { return p - perp(l.v) * side(l, p) / _norm_(l.v); }

bool cmpProj(line l, pt a, pt b) { return dot(l.v , a) < dot(l.v, b); }
pt segPoint(pt a, pt b, pt p) {
    if (a != b) {
        line l(a, b);
        if (cmpProj(l, a, p) && cmpProj(l, p, b)) return proj(l, p);
    }
    if (abs(p - a) < abs(p - b)) return a;
    else return b;
}

vector<pt> p;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> x >> y, cin) {
        M = {x, y}, p.clear(), ansAbs = FLT_MAX;
        cin >> n, n++;
        if (n == 1) {
            cin >> t >> u;
            cout << t << endl << u << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
            cin >> t >> u, p.push_back(pt(t, u));
        for (int i = 0; i < n - 1; i++) {
            temp = segPoint(p[i], p[i + 1], M);
            if (abs(temp - M) < ansAbs) ans = temp, ansAbs = abs(temp - M);
        }
        cout << fixed << setprecision(4) << ans.x << endl << ans.y << endl;
    }
    return 0;
}
