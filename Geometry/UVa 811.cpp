//Question of basically finding the convex hull and some use of bitmask
//though the solution's answers doesn't matches all the test cases on uDebug, it gets AC. Maybe there is some problems with the soutions on uDebug

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
T cross(pt p, pt q) { return p.x * q.y - p.y * q.x; }
double orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

vector<pt> p, q, ch;
double t, u, v[25], l[25], ansp, anslen;
int n, anscnt, ans, ansv;

double perimeter(vector<pt>& p) {
    double ans = 0;
    int n = p.size();
    for (int i = 0; i < n; i++)
        ans += abs(p[i] - p[(i + 1) % n]);
    return ans;
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
    ch.push_back(p[n - 1]), ch.push_back(p[0]), ch.push_back(p[1]);
    int k = 2;
    ind = 3;
    while (k < n) {
        if (orient(ch[ind - 2], ch[ind - 1], p[k]) < 0) ch.pop_back(), ind--;
        else ch.push_back(p[k++]), ind++;
    }
    ch.pop_back();
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while (cin >> n, n) {
        p.clear();
        if (tc != 1) cout << endl;
        for (int i = 0; i < n; i++)
            cin >> t >> u >> v[i] >> l[i], p.push_back({t, u});
        if (n == 2) {
            cout << "Forest " << tc++ << endl;
            if (v[0] != v[1]) {
                cout << "Cut these trees: " << (v[0] < v[1] ? 1 : 2) << endl;
                cout << "Extra wood: " << (v[0] < v[1] ? l[0] : l[1]) << endl;
            } else {
                cout << "Cut these trees: " << (l[0] < l[1] ? 1 : 2) << endl;
                cout << "Extra wood: " << (l[0] < l[1] ? l[0] : l[1]) << endl;
            }
        } else {
            ansv = INT_MAX, anscnt = INT_MAX;
            for (int i = 1; i < (1 << n); i++) {
                q.clear(), ch.clear();
                int j = i, tempcnt = 0, tempv = 0, ind = 0;
                double templen = 0, tempp;
                while (ind < n) {
                    if (j & 1) templen += l[ind], tempv += v[ind], tempcnt++;
                    else q.push_back(p[ind]);
                    j >>= 1, ind++;
                }
                convexHull(q, ch);
                if ((tempv < ansv || tempv == ansv && tempcnt < anscnt) && ((tempp = perimeter(ch)) <= templen))
                    ans = i, ansv = tempv, anscnt = tempcnt, ansp = tempp, anslen = templen;
            }
            cout << "Forest " << tc++ << endl;
            cout << "Cut these trees:";
            int ind = 1;
            while (ans) {
                if (ans & 1) cout << " " << ind;
                ind++, ans >>= 1;
            }
            cout << endl;
            cout << "Extra wood: " << fixed << setprecision(2) << anslen - ansp << endl;
        }
    }
    return 0;
}
