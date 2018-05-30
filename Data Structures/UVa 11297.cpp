#include<bits/stdc++.h>
#define INF 1000000000
#define SZ 550
#define right(x) (2 * x + 1)
#define left(x) (2 * x)
using namespace std;

typedef pair<int, int> pii;

int v[SZ][SZ];
pii st[SZ][4 * SZ];

void buildST(int r, int ind, int L, int R) {
    if (L == R) st[r][ind] = pii(v[r][L], v[r][L]);
    else {
        int t = (L + R) / 2;
        buildST(r, left(ind), L, t);
        buildST(r, right(ind), t + 1, R);
        st[r][ind].second = min(st[r][left(ind)].second, st[r][right(ind)].second);
        st[r][ind].first = max(st[r][left(ind)].first, st[r][right(ind)].first);
    }
}

pii query(int r, int ind, int L, int R, int l, int h) {
    if (R < l || L > h) return pii(-INF, INF);
    if (l <= L && R <= h) return st[r][ind];
    int t = (L + R) / 2;
    pii a = query(r, left(ind), L, t, l, h), b = query(r, right(ind), t + 1, R, l, h);
    return pii(max(a.first, b.first), min(a.second, b.second));
}

void update(int r, int ind, int L, int R, int pos, int val) {
    if (L == R && L == pos) st[r][ind].first = val, st[r][ind].second = val;
    else {
        int t = (L + R) / 2, a = left(ind), b = right(ind);
        if (pos > t) update(r, right(ind), t + 1, R, pos, val);
        else update(r, left(ind), L, t, pos, val);
        st[r][ind] = pii(max(st[r][a].first, st[r][b].first), min(st[r][a].second, st[r][b].second));
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int N, Q, a, b, c, d;
    char ch;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> v[i][j];
        buildST(i, 1, 0, N - 1);
    }
    cin >> Q;
    while (Q--) {
        cin >> ch;
        if (ch == 'q') {
            cin >> a >> b >> c >> d;
            int ansmin = INF, ansmax = -INF;
            for (int i = a - 1; i < c; i++) {
                pii qry = query(i, 1, 0, N - 1, b - 1, d - 1);
                ansmin = min(ansmin, qry.second), ansmax = max(ansmax, qry.first);
            }
            cout << ansmax << " " << ansmin << endl;
        } else {
            cin >> a >> b >> c;
            update(a - 1, 1, 0, N - 1, b - 1, c);
        }
    }
    return 0;
}
