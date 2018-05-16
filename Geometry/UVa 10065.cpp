//An easy problem involving the calcultion of convex hull of a set of points
//Take care of when you calulate the areas

#include<bits/stdc++.h>
#define epsilon 1e-9
using namespace std;

struct pt {
    double x, y;
    pt operator+(pt p) { return {x + p.x, y + p.y}; }
    pt operator-(pt p) { return {x - p.x, y - p.y}; }
    pt operator*(double t) { return {x * t, y * t}; }
    pt operator/(double t) { return {x / t, y / t}; }
};

double abs(pt p) { return sqrt(p.x * p.x + p.y * p.y); }
double cross(pt p, pt q) { return p.x * q.y - p.y * q.x; }
double orient(pt a, pt b, pt c) { return cross(b - a, c - a); }
ostream& operator<< (ostream& os, pt p) {return os << "(" << p.x << "," << p.y << ")"; }

pt pivot;
bool cmp(pt& x, pt& y) {
    double t = orient(x, y, pivot);
    if (abs(t) < epsilon)
        return abs(x - pivot) < abs(y - pivot);
    return t > 0;
}

void convexHull(vector<pt>& p, vector<pt>& ch) {
    int n = p.size(), ind = 0;
    for (int i = 1; i < n; i++)
        if (p[ind].y > p[i].y || p[ind].y == p[i].y && p[i].x > p[ind].x) ind = i;
    pivot = p[ind], p[ind] = p[0], p[0] = pivot;
    sort(p.begin(), p.end(), cmp);
    ch.clear(), ch.push_back(p[n - 1]), ch.push_back(p[0]), ch.push_back(p[1]);
    int k = 2;
    ind = 3;
    while (k < n) {
        if (orient(ch[ind - 2], ch[ind - 1], p[k]) < 0) ch.pop_back(), ind--;
        else ch.push_back(p[k++]), ind++;
    }
    ch.pop_back();
}

double areaPolygon(vector<pt> p) {
    double area = 0.0;
    for(int i = 0, n = p.size(); i < n; i++)
        area += cross(p[i], p[(i + 1) % n]);
    return abs(area) / 2.0;
}

vector<pt> p, ch;
double t, u;
int n, tc = 1;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n) {
        p.resize(n);
        for (int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        t = areaPolygon(p);
        convexHull(p, ch);
        u = areaPolygon(ch);
        cout << "Tile #" << tc++ << endl << "Wasted Space = " << fixed << setprecision(2) << (u - t) / u * 100 << " %"
             << endl << endl;
    }
    return 0;
}
