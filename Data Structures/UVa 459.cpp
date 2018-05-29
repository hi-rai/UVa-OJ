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
    int TC, n, k, c, w;
    char ch, t, u;
    cin >> TC;
    cin.ignore().ignore();
    while (TC--) {
        cin.get(ch).ignore(), n = (int)(ch - 'A') + 1;
        s.init(n);
        while(cin.get(t),cin && t != '\n') {
            cin.get(u).ignore();
            s.unionSet(t - 'A', u - 'A');
        }
        cout << s.totSet() << endl;
        if(TC) cout << endl;
    }
    return 0;
}
