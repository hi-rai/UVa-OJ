//An application of Pick's Theorem
//Take care to count all the boundary points with integer coordinates

#include<bits/stdc++.h>
using namespace std;

struct pt {
    int x, y;
    pt operator+(pt p) { return {x + p.x, y + p.y}; }
    pt operator-(pt p) { return {x - p.x, y - p.y}; }
    pt operator*(int k) { return {k * x, k * y}; }
    pt operator/(int k) { return {x / k, y / k}; }
};

long long cross(pt p, pt q) { return (long long)(p.x) * q.y - (long long)(p.y) * q.x; }
long long areaPolygon(pt p[], int n) {
    long long area = 0;
    for (int i = 0; i < n; i++)
        area += cross(p[i], p[(i + 1) % n]);
    return abs(area);
}

int gcd(int x, int y) {
    return x % y ? gcd(y, x % y) : y;
}

pt p[1005];
int N, b;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> N, N) {
        b = 0;
        cin >> p[0].x >> p[0].y;
        for (int i = 1; i < N; i++) {
            cin >> p[i].x >> p[i].y;
            if (p[i].x == p[i - 1].x) b += abs(p[i].y - p[i - 1].y);
            else if (p[i].y == p[i - 1].y) b += abs(p[i].x - p[i - 1].x);
            else b += gcd(abs(p[i].y - p[i - 1].y), abs(p[i - 1].x - p[i].x));
        }
        if (p[0].x == p[N - 1].x) b += abs(p[0].y - p[N - 1].y);
        else if (p[0].y == p[N - 1].y) b += abs(p[0].x - p[N - 1].x);
        else b += gcd(abs(p[0].y - p[N - 1].y), abs(p[N - 1].x - p[0].x));
        cout << (areaPolygon(p, N) + 2 - b) / 2 << endl;
    }
    return 0;
}
