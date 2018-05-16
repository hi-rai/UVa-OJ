//An easy problem involving the calculation of area of a polygon.

#include<bits/stdc++.h>
#define epsilon 1e-9
using namespace std;

struct pt {
    double x, y;
    pt(double a, double b) : x(a), y(b) {}
    pt() : x(0), y(0) {}
    pt operator+ (pt p) { return { x + p.x, y + p.y}; }
    pt operator- (pt p) { return { x - p.x, y - p.y}; }
    pt operator* (double k) { return { k * x, k * y }; }
    pt operator/ (double k) { return { x / k, y / k }; }
    bool operator== (pt p) { return (abs(x - p.x) < epsilon && abs(y - p.y) < epsilon);}
    bool operator!= (pt p) { return (abs(x - p.x) >= epsilon || abs(y - p.y) >= epsilon);}
};

double cross(pt p, pt q) { return p.x * q.y - p.y * q.x; }
double areaPolygon(pt p[], int n) {
    double area = 0.0;
    for(int i = 0; i < n; i++)
        area += cross(p[i], p[(i + 1) % n]);
    return abs(area) / 2.0;
}


int n, TC;
double t, u, v, w;
pt p[10005];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        double area = areaPolygon(p, n);
        cin >> w >> t >> u >> v;
        t /= 100, u /= w, v /= w, u /= area, v /= area;
        if (t - u < 0) cout << "Lack of water. ";
        if (max(0.0, t - u) + v > 1.0) cout << "Excess of water. ";
        cout << "Final percentage: " << (int)(min(max(0.0, t - u) + v, 1.0) * 100) << "%" << endl;
    }
    return 0;
}
