//Use the same concept as finding the shortest distance between a pair of points among given points, with slight modification

#include<bits/stdc++.h>
using namespace std;

double ans;
int n;
struct pt {
    int x, y;
    pt operator-(pt p) { return {x - p.x, y - p.y}; }
    bool operator<(pt p) { return (x < p.x || x == p.x && y < p.y); }
} p[100005];

double abs(pt p) { return sqrt(double(p.x) * p.x + (double)(p.y) * p.y); }

void calc(int i, int j) {
    int k = (j - i + 1), m = (i + j) / 2;
    if (k < 2) return;
    if (k == 2) {
        int t = abs(p[i].x - p[i + 1].x), u = abs(p[i].y - p[i + 1].y);
        double d = abs(p[i] - p[i + 1]);
        ans = min(ans, max(t, u) * d / sqrt(t * t + u * u));
    }
    calc(i, m), calc(m + 1, j);
    for (int a = m + 1; p[a].x - p[m].x < ans && a < n; a++)
        for (int b = m; p[a].x - p[b].x < ans && b > 0; b--) {
            int t = abs(p[a].x - p[b].x), u = abs(p[a].y - p[b].y);
            double d = abs(p[a] - p[b]);
            ans = min(ans, max(t, u) * d / sqrt(t * t + u * u));
        }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while (scanf("%d", &n) != EOF) {
        ans = FLT_MAX;
        for (int i = 0; i < n; i++)
            scanf("%d %d", &p[i].x, &p[i].y);
        sort(p, p +n );
        calc(0, n - 1);
        printf("%d\n", (int) ans);
    }
    return 0;
}
