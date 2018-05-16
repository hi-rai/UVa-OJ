//A combined application of spherical coordinate system and bellman ford's algorithm
//Take care to round the distances to int from float for any calculations

#include<bits/stdc++.h>
#define PI 3.141592653589793
#define R 6378.0
#define INF 1000000000
using namespace std;

struct pt {
    double x, y, z;
    pt() : x(0), y(0), z(0) {}
    pt(double x, double y, double z) : x(x), y(y), z(z) {}
    pt(double t, double u) : x(R * cos(PI * t / 180) * cos(PI * u / 180)), y(R * cos(PI * t / 180) * sin(PI * u / 180)),
                             z(R * sin(PI * t / 180)) {}
    pt operator+(pt p) { return {x + p.x, y + p.y, z + p.z}; }
    pt operator-(pt p) { return {x - p.x, y - p.y, z - p.z}; }
    pt operator*(double t) { return {x * t, y * t, z * t}; }
    pt operator/(double t) { return {x / t, y / t, z / t}; }
};

double abs(pt p) { return sqrt(p.x * p.x + p.y * p.y + p.z * p.z); }
ostream& operator<< (ostream& os, pt p) {return os << "(" << p.x << "," << p.y << "," << p.z << ")"; }
int rnd(double t) { return (((int) (t * 10)) % 10 >= 5 ? ((int) t) + 1 : (int)t); }

map<string, int> ind;
pt p[105];
string s, t;
double u, v;
int m, n, q, tc = 1, dist[105][105];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m >> q, n) {
        ind.clear();
        if (tc != 1) cout << endl;
        for (int i = 0; i < n; i++)
            cin >> s >> u >> v, ind[s] = i, p[i] = pt(u, v);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = INF;
        for (int i = 0; i < m; i++) {
            cin >> s >> t;
            int a = ind[s], b = ind[t];
            dist[a][b] = rnd(2.0 * R * asin(abs(p[ind[s]] - p[ind[t]]) / 2.0 / R));
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        cout << "Case #" << tc++ << endl;
        for (int i = 0; i < q; i++) {
            cin >> s >> t;
            int a = ind[s], b = ind[t];
            if (dist[a][b] == INF) cout << "no route exists" << endl;
            else cout << fixed << setprecision(0) << dist[a][b] << " km" << endl;
        }
    }
    return 0;
}
