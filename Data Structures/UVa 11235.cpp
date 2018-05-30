//use segment tree
//to calulate the max frequency value of a node, take the maximum of that of its childrens and the frequency at the partition
//edge if both are equal

#include<bits/stdc++.h>
#define INF 100000000
#define SZ 100005
#define right(x) (2 * x + 1)
#define left(x) (2 * x)
using namespace std;

typedef pair<int, int> pii;

int v[SZ];
pii st[5 * SZ];

void buildST(int ind, int L, int R) {
    if (L == R) st[ind] = pii(v[L], 1);
    else {
        int t = (L + R) / 2;
        int a = left(ind), b = right(ind);
        buildST(a, L, t);
        buildST(b, t + 1, R);
        if (st[a].first == st[b].first) st[ind] = pii(st[a].first, st[b].second + st[a].second);
        else if (v[t] == v[t + 1]) {
            int p = (lower_bound(v + L, v + t + 1, v[t]) - v);
            int q = upper_bound(v + t + 1, v + R + 1, v[t + 1]) - v - 1;
            if (q - p + 1 > st[a].second && q - p + 1 > st[b].second) st[ind] = pii(v[t], q - p + 1);
            else if (st[a].second > st[b].second) st[ind] = st[a];
            else st[ind] = st[b];
        } else {
            if (st[a].second > st[b].second) st[ind] = st[a];
            else st[ind] = st[b];
        }
    }
}

pii query(int ind, int L, int R, int l, int r) {
    if (R < l || L > r) return pii(-INF, -1);
    if (l <= L && R <= r) return st[ind];
    int t = (L + R) / 2;
    pii a = query(left(ind), L, t, l, r), b = query(right(ind), t + 1, R, l, r);
    if (a.second == -1) return b;
    else if (b.second == -1) return a;
    if (a.first == b.first) return pii(a.first, a.second + b.second);
    else if (v[t] == v[t + 1]) {
        int p = lower_bound(v + max(l, L), v + t + 1, v[t]) - v;
        int q = upper_bound(v + t + 1, v + min(r, R) + 1, v[t + 1]) - v - 1;
        if (q - p + 1 > a.second && q - p + 1 > b.second) return pii(v[t], q - p + 1);
        else if (a.second > b.second) return a;
        else return b;
    } else {
        if (a.second > b.second) return a;
        else return b;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, q, t, u;
    while (cin >> n >> q, n) {
        for (int i = 0; i < n; i++)
            cin >> v[i];
        buildST(1, 0, n - 1);
        for (int i = 0; i < q; i++)
            cin >> t >> u, cout << query(1, 0, n - 1, t - 1, u - 1).second << endl;
    }
    return 0;
}
