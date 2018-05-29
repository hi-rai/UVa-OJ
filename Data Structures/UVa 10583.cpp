#include<bits/stdc++.h>
#define SZ 50005
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
    int setCount() { return setCnt; }
}s;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int M, N, t, u, tc = 1;
    while(cin >> N >> M, N) {
        s.init(N);
        while(M--) cin >> t >> u, s.unionSet(t - 1, u - 1);
        cout << "Case " << tc++ << ": " << s.setCount() << endl;
    }
    return 0;
}
