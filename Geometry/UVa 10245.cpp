//Use divide and conquer technique to solve the problem.

#include<bits/stdc++.h>
#define epsilon 1e-9
using namespace std;

struct pt {
    double x, y;
    pt operator- (pt p) { return { x - p.x, y - p.y}; }
    bool operator< (pt p) { return (x < p.x || abs(x - p.x) < epsilon && y < p.y); }
} p[10005];

int N;
double dist;

double abs(pt p) { return sqrt(p.x * p.x + p.y * p.y); }
void calc(int i, int j) {
    int n = (j - i + 1), mid = (i + j) / 2;
    if (n == 1) return;
    if (n == 2) {
        dist = min(dist, abs(p[j] - p[i]));
        return;
    }
    calc(i, mid), calc(mid + 1, j);
    for (int i = mid + 1; p[i].x - p[mid].x < dist && i < N; i++) {
        for (int j = mid; p[i].x - p[j].x < dist && j >= 0; j--)
            dist = min(dist, abs(p[i] - p[j]));
    }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> N, N) {
        dist = FLT_MAX;
        for (int i = 0; i < N; i++)
            cin >> p[i].x >> p[i].y;
        sort(p, p + N);
        calc(0, N - 1);
        if(dist >= 10000.0)   cout << "INFINITY" << endl;
        else cout << fixed << setprecision(4) << dist << endl;
    }
    return 0;
}
