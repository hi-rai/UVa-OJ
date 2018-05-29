//An easy problem. Use UFDS to keep track of the connected components

#include<bits/stdc++.h>
using namespace std;

int p[105], r[105], c[105], n;
float x[105], y[105], R[105];

void init(int n) {
    for (int i = 0; i < n; i++)
        p[i] = i, r[i] = 0, c[i] = 1;
}

int findSet(int x) {
    return x == p[x] ? x : p[x] = findSet(p[x]);
}

void unionSet(int x, int y) {
    int a = findSet(x), b = findSet(y);
    if (a == b) return;
    if (r[a] < r[b])
        p[a] = b, c[b] += c[a];
    else
        p[b] = a, c[a] += c[b];
    if (r[a] == r[b]) r[a]++;
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n != -1) {
        init(n);
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i] >> R[i];
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                double t = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                if (abs(R[i] - R[j]) < t && t < R[i] + R[j])
                    unionSet(i, j);
            }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, c[i]);
        cout << "The largest component contains " << ans << (ans != 1 ? " rings." : " ring.") << endl;
    }
    return 0;
}
