//the problem involves careful analysis of different possible cases
//first case is when there is no intersection
//second is when one of the rectangles is completely inside the other
//third case is when one of the rectangles intersects the other rectangle through one or both of the either of its parallel edges
//last case is when one of the rectangles intersects the other rectangle through either of its two perpendicular edges

#include<bits/stdc++.h>
using namespace std;

struct pt {
    int x, y;
    bool operator<(const pt &p) { return x <= p.x && y <= p.y; }
};

bool check(pt a, pt b, pt c, pt d, pt& e, pt& f) {
    if (a.x <= c.x && d.x <= b.x) {
        e.y = max(a.y, c.y), f.y = min(d.y, b.y);
        e.x = c.x, f.x = d.x;
        return true;
    }
    if (a.y <= c.y && d.y <= b.y) {
        e.x = max(a.x, c.x), f.x = min(d.x, b.x);
        e.y = c.y, f.y = d.y;
        return true;
    }
    return false;
}

void prPoint(pt a, pt b) {
    cout << a.x << " " << a.y << " " << b.x << " " << b.y << endl;
}

int n;
pt a, b, c, d, e, f;
bool chk = true;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        if(chk)   chk = false;
        else cout << endl;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        if (b.x <= c.x || a.x >= d.x || a.y >= d.y || b.y <= c.y) cout << "No Overlap" << endl;
        else if (a < c && d < b) prPoint(c, d);
        else if (c < a && b < d) prPoint(a, b);
        else if (check(a, b, c, d, e, f)) prPoint(e, f);
        else if (check(c, d, a, b, e, f)) prPoint(e, f);
        else if (a < d && c < a) prPoint(a, d);
        else if (c < b && b < d) prPoint(c, b);
        else if (c.x < a.x) cout << a.x << " " << c.y << " " << d.x << " " << b.y << endl;
        else cout << c.x << " " << a.y << " " << b.x << " " << d.y << endl;
    }
    return 0;
}
