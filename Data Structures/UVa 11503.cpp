#include<bits/stdc++.h>
#define SZ 200005
using namespace std;

map<string, int> ind;

class UFDS {
    int p[SZ], r[SZ], s[SZ];
public:
    void init(int n) {
        for(int i = 0; i < n; i++)
            p[i] = i, r[i] = 0, s[i] = 1;
    }
    int findSet(int x) { return x == p[x] ? x : p[x] = findSet(p[x]); }
    bool sameSet(int x, int y) { return findSet(x) == findSet(y); }
    void unionSet(int x, int y) {
        int a = findSet(x), b = findSet(y);
        if(a != b) {
            if(r[a] > r[b])  p[b] = a, s[a] += s[b];
            else p[a] = b, s[b] += s[a];
            if(r[a] == r[b]) r[b]++;
        }
    }
    int sizeOf(int x) { return s[findSet(x)]; }
}s;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC, n, k;
    string t, u;
    cin >> TC;
    while (TC--) {
        cin >> n;
        s.init(2 * n), ind.clear(), k = 0;
        while (n--) {
            cin >> t >> u;
            if (ind.count(t) == 0) ind[t] = k++;
            if (ind.count(u) == 0) ind[u] = k++;
            int a = ind[t], b = ind[u];
            s.unionSet(a, b);
            cout << s.sizeOf(a) << endl;
        }
    }
    return 0;
}
