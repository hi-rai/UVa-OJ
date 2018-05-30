//We can binary search the answer and use UFDS to keep track of stations that can communicate

#include<bits/stdc++.h>
#define SZ 500005
using namespace std;

class UFDS {
    int p[SZ], r[SZ], setCnt;
public:
    void init(int n) {
        for(int i = 0; i < n; i++)
            p[i] = i, r[i] = 0;
        setCnt = n;
    }
    int findSet(int x) { return x == p[x] ? x : p[x] = findSet(p[x]); }
    bool sameSet(int x, int y) { return findSet(x) == findSet(y); }
    void unionSet(int x, int y) {
        int a = findSet(x), b = findSet(y);
        if(a != b) {
            if(r[a] > r[b])  p[b] = a;
            else p[a] = b;
            if(r[a] == r[b]) r[b]++;
            setCnt--;
        }
    }
    int totSet() { return setCnt; }
}s;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int TC, x[505], y[505], S, P, tc = 1;
    double dist[505][505], l, h;
    cin >> TC;
    while (TC--) {
        cin >> S >> P;
        if(S >= P) {
            for(int i = 0; i < P; i++)
                cin >> x[i] >> y[i];
            cout << "0.00" << endl;
            continue;
        }
        h = -1, l = 0;
        for(int i = 0; i < P; i++) {
            cin >> x[i] >> y[i];
            for(int j = 0; j < i; j++)
                dist[j][i] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)), h = max(h, dist[j][i]);
        }
        S = max(S, 1);
        while(true) {
            s.init(P);
            double mid = (l + h) / 2;
            for(int i = 0; i < P; i++)
                for(int j = 0; j < i; j++)
                if(dist[j][i] <= mid)
                    s.unionSet(i, j);
            if(s.totSet() <= S) h = mid;
            else l = mid;
            if(s.totSet() <= S && abs(l - h) < 1e-4)   break;
        }
        cout << fixed << setprecision(2) << h << endl;
    }
    return 0;
}
