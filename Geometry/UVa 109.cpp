//An easy problem once you know how to find the convex hull of a set of points, area of a closed polygon and to check whether a
//point is within a closed polygon

#include<bits/stdc++.h>
#define epsilon 1e-9
using namespace std;

typedef double T;

struct pt {
    double x, y;
    pt operator+(pt p) { return {x + p.x, y + p.y}; }
    pt operator-(pt p) { return {x - p.x, y - p.y}; }
    pt operator*(double t) { return {x * t, y * t}; }
    pt operator/(double t) { return {x / t, y / t}; }
};

double abs(pt p) { return sqrt(p.x * p.x + p.y * p.y); }
T dot(pt p, pt q) { return p.x * q.x + p.y * q.y; }
T cross(pt p, pt q) { return p.x * q.y - p.y * q.x; }
double orient(pt a, pt b, pt c) { return cross(b - a, c - a); }
bool inDisk(pt a, pt b, pt c) { return dot(b - c, a - c) <= 0; }
bool onSegment(pt a, pt b, pt c) { return abs(orient(a, b, c)) <= epsilon && inDisk(a, b, c); }

double areaPolygon(vector<pt> p) {
    double area = 0.0;
    for(int i = 0, n = p.size(); i < n; i++)
        area += cross(p[i], p[(i + 1) % n]);
    return abs(area) / 2.0;
}

bool half(pt a, pt p) { return p.y >= a.y; }
bool crossesRay(pt a, pt b, pt p) { return (half(p, a) - half(p, b)) * orient(p, b, a) > 0; }
bool inPolygon(vector<pt> p, pt a, bool strict) {
    int numCrossings = 0;
    for(int i = 0, n = p.size(); i < n; i++) {
        if(onSegment(p[i], p[(i + 1) % n], a))
            return !strict;
        if(crossesRay(p[i], p[(i + 1) % n], a))   numCrossings++;
    }
    return numCrossings & 1;
}

pt pivot;
bool cmp(pt& x, pt& y) {
    double t = orient(x, y, pivot);
    if (abs(t) < epsilon)
        return abs(x - pivot) < abs(y - pivot);
    return t > 0;
}

void convexHull(vector<pt>& p, vector<pt>& ch) {
    int n = p.size(), ind = 0;
    if (n <= 3) {
        ch = p;
        return;
    }
    for (int i = 1; i < n; i++)
        if (p[ind].y > p[i].y || p[ind].y == p[i].y && p[i].x > p[ind].x) ind = i;
    pivot = p[ind], p[ind] = p[0], p[0] = pivot;
    sort(++p.begin(), p.end(), cmp);
    ch.clear(), ch.push_back(p[n - 1]), ch.push_back(p[0]), ch.push_back(p[1]);
    int k = 2;
    ind = 3;
    while (k < n) {
        if (orient(ch[ind - 2], ch[ind - 1], p[k]) < 0) ch.pop_back(), ind--;
        else ch.push_back(p[k++]), ind++;
    }
    ch.pop_back();
}

vector<pt> p[25], k[25];
double area[25], t, u, ans = 0;
bitset<25> dest = 0;
int cnt, n;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cnt = 0;
    while (cin >> n, n != -1) {
        cnt++;
        for (int i = 0; i < n; i++)
            cin >> t >> u, p[cnt - 1].push_back({t, u});
        convexHull(p[cnt - 1], k[cnt - 1]);
        area[cnt - 1] = areaPolygon(k[cnt - 1]);
    }
    while (cin >> t >> u) {
        for (int i = 0; i < cnt; i++)
            if (!dest[i] && inPolygon(k[i], {t, u}, false))
                dest[i] = true, ans += area[i];
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
