//An easy problem of involving finding the intersection point of two line segments

#include<bits/stdc++.h>
#define epsilon 1e-9
using namespace std;

typedef double T;

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

T dot(pt p, pt q) { return p.x * q.x + p.y * q.y; }
T cross(pt p, pt q) { return p.x * q.y - p.y * q.x; }
double orient(pt a, pt b, pt c) { return cross(b - a, c - a); }
bool inDisk(pt a, pt b, pt c) { return dot(b - c, a - c) <= 0; }
bool onSegment(pt a, pt b, pt c) { return abs(orient(a, b, c)) <= epsilon && inDisk(a, b, c); }

bool propInter(pt a, pt b, pt c, pt d, pt& p) {
    double oa = orient(c, d, a);
    double ob = orient(c, d, b);
    double oc = orient(a, b, c);
    double od = orient(a, b, d);
    if(oa * ob < 0 && oc * od < 0) {
        p = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}

set<pair<T, T> > inter(pt a, pt b, pt c, pt d) {
    pt t;
    if (propInter(a, b, c, d, t)) return {make_pair(t.x, t.y)};
    set<pair<T, T> > ret;
    if (onSegment(a, b, c)) ret.insert(make_pair(c.x, c.y));
    if (onSegment(a, b, d)) ret.insert(make_pair(d.x, d.y));
    if (onSegment(c, d, a)) ret.insert(make_pair(a.x, a.y));
    if (onSegment(c, d, b)) ret.insert(make_pair(b.x, b.y));
    return ret;
}

int n, ans= 0;
set<int> valid;
pair<pt,pt> sticks[100005];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n) {
        valid.clear(), ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> sticks[i].first.x >> sticks[i].first.y >> sticks[i].second.x >> sticks[i].second.y;
            ans++;
            for (auto it = valid.begin(); it != valid.end();) {
                auto jt = it++;
                if (!inter(sticks[i].first, sticks[i].second, sticks[*jt].first, sticks[*jt].second).empty())
                    valid.erase(jt), ans--;
            }
            valid.insert(i);
        }
        cout << "Top sticks:";
        for (auto i:valid) {
            if (i != (*valid.begin())) cout << ",";
            cout << " " << i + 1;
        }
        cout << "." << endl;
    }
    return 0;
}
