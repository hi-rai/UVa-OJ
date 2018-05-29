#include<bits/stdc++.h>
#define SZ 30005
using namespace std;

class UFDS {
    int p[SZ], r[SZ], s[SZ], mxm;
public:
    void init(int n) {
        for(int i = 0; i < n; i++)
            p[i] = i, r[i] = 0, s[i] = 1;
        mxm = 1;
    }
    int findSet(int x) { return x == p[x] ? x : p[x] = findSet(p[x]); }
    bool sameSet(int x, int y) { return findSet(x) == findSet(y); }
    void unionSet(int x, int y) {
        int a = findSet(x), b = findSet(y);
        if(a != b) {
            if(r[a] > r[b])  p[b] = a, s[a] += s[b], mxm = max(mxm, s[a]);
            else p[a] = b, s[b] += s[a], mxm = max(mxm, s[b]);
            if(r[a] == r[b]) r[b]++;
        }
    }
    int findMxm() { return mxm; }
}s;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC, M, N, t, u;
    cin >> TC;
    while(TC--) {
        cin >> N >> M;
        s.init(N);
        while(M--) cin >> t >> u, s.unionSet(t - 1, u - 1);
        cout << s.findMxm() << endl;
    }
    return 0;
}
