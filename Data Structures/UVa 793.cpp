#include<bits/stdc++.h>
#define SZ 500005
using namespace std;

class UFDS {
    int p[SZ], r[SZ];
public:
    void init(int n) {
        for(int i = 0; i < n; i++)
            p[i] = i, r[i] = 0;
    }
    int findSet(int x) { return x == p[x] ? x : p[x] = findSet(p[x]); }
    bool sameSet(int x, int y) { return findSet(x) == findSet(y); }
    void unionSet(int x, int y) {
        int a = findSet(x), b = findSet(y);
        if(a != b) {
            if(r[a] > r[b])  p[b] = a;
            else p[a] = b;
            if(r[a] == r[b]) r[b]++;
        }
    }
}s;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int TC, n, k, c, w, t, u;
    char ch, str[100];
    scanf("%d ", &TC);
    while (TC--) {
        scanf("%d", &n), fgets(str, 100, stdin);
        s.init(n), c = 0, w = 0;
        while(fgets(str, 100, stdin) && sscanf(str, "%c %d %d", &ch, &t, &u) == 3) {
            if(ch == 'c') s.unionSet(t - 1, u - 1);
            else if(s.sameSet(t - 1, u - 1)) c++;
            else w++;
        }
        printf("%d,%d\n", c, w);
        if(TC) printf("\n");
    }
    return 0;
}
