//A simple problem of finding the circumcenter and circumradius of a triangle
//The only difficulty is producing the correct output format

#include<bits/stdc++.h>
using namespace std;

double t, u;

struct pt {
    double x, y;
    pt operator+ (pt p) { return {x + p.x, y + p.y}; }
    pt operator- (pt p) { return {x - p.x, y - p.y}; }
    pt operator* (double d) { return {x * d, y * d}; }
    pt operator/ (double d) { return {x / d, y / d}; }
}a[3];

pt perp(pt p) { return {-p.y, p.x}; }
double cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }
double norm(pt a) { return a.x * a.x + a.y * a.y; }
ostream& operator<< (ostream& os, pt p) {return os << "(" << p.x << "," << p.y << ")"; }

pt circumCenter(pt a, pt b, pt c) {
    b = b - a, c = c - a;
    double t = cross(b, c);
    assert(t != 0);
    return a + perp(b * norm(c) - c * norm(b)) / 2 / t;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (1) {
        for (int i = 0; i < 3; i++) {
            cin >> t >> u;
            if (!cin) return 0;
            a[i] = {t, u};
        }
        pt p = circumCenter(a[0], a[1], a[2]);
        double r = sqrt(norm(p - a[0]));
        cout << fixed << setprecision(3);
        if(p.x) cout << "(x " << (p.x < 0 ? '+' : '-') << " " << abs(p.x) << ")^2 + " ;
        else cout << "x^2 + " ;
        if(p.y) cout << "(y " << (p.y < 0 ? '+' : '-') << " " << abs(p.y) << ")^2 = ";
        else    cout<< "y^2 = ";
        if(r)   cout << r << "^2" << endl;
        else    cout << 0 <<endl;
        double c = p.x * p.x + p.y * p.y - r * r;
        cout << "x^2 + y^2 ";
        if(p.x) cout << (p.x < 0 ? '+' : '-') << " " << abs(2 * p.x) << "x ";
        if(p.y) cout << (p.y < 0 ? '+' : '-') << " " << abs(2 * p.y) << "y ";
        if(c)   cout << (c < 0 ? '-' : '+') << " " << abs(c) << " ";
        cout << "= 0" << endl;
        cout<<endl;
    }
    return 0;
}
