//Use segment tree wiht lazy updates

#include<bits/stdc++.h>
#define SZ 1025000
#define right(x) (2 * x + 1)
#define left(x) (2 * x)
using namespace std;

bitset<4 * SZ> v;
int st[4 * SZ];
char lazy[4 * SZ];

void buildST(int ind, int L, int R) {
    if (L == R) st[ind] = v[L];
    else {
        int t = (L + R) / 2, a = left(ind), b = right(ind);
        buildST(a, L, t);
        buildST(b, t + 1, R);
        st[ind] = st[a] + st[b];
    }
}

void updateLazy(int ind, int L, int R) {
    int a = left(ind), b = right(ind);
    if (lazy[ind] == 'I') {
        st[ind] = R - L + 1 - st[ind];
        if (L != R) {
            if (lazy[a] == 'I') lazy[a] = 'A';
            else if (lazy[a] == 'E') lazy[a] = 'F';
            else if (lazy[a] == 'F') lazy[a] = 'E';
            else if (lazy[a] == 'A') lazy[a] = 'I';
            if (lazy[b] == 'I') lazy[b] = 'A';
            else if (lazy[b] == 'E') lazy[b] = 'F';
            else if (lazy[b] == 'F') lazy[b] = 'E';
            else if (lazy[b] == 'A') lazy[b] = 'I';
        }
    } else if (lazy[ind] == 'E') {
        st[ind] = 0;
        if (L != R) lazy[a] = lazy[b] = 'E';
    } else if (lazy[ind] == 'F') {
        st[ind] = R - L + 1;
        if (L != R) lazy[a] = lazy[b] = 'F';
    }
    lazy[ind] = 'A';
}

int query(int ind, int L, int R, int l, int r) {
    updateLazy(ind, L, R);
    if (r < L || R < l) return 0;
    if (l <= L && R <= r) return st[ind];
    int t = (L + R) / 2;
    return query(left(ind), L, t, l, r) + query(right(ind), t + 1, R, l, r);
}

void update(int ind, int L, int R, int l, int r, char val) {
    updateLazy(ind, L, R);
    if (r < L || R < l) return;
    if (l <= L && R <= r) {
        lazy[ind] = val;
        updateLazy(ind, L, R);
        return;
    }
    int t = (L + R) / 2, a = left(ind), b = right(ind);
    update(a, L, t, l, r, val), update(b, t + 1, R, l, r, val);
    st[ind] = st[a] + st[b];
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int tc = 1, TC, ind, M, Q, T, m, a, b, q;
    string str;
    char c;
    cin >> TC;
    while (TC--) {
        memset(lazy, 'A', sizeof lazy);
        v.reset(), ind = 0;
        cin >> M;
        while (M--) {
            cin >> T >> str;
            m = str.length();
            for (int i = 0; i < m; i++)
                if (str[i] == '1')
                    for (int j = 0; j < T; j++)
                        v[ind + j * m + i] = true;
            ind += T * m;
        }
        buildST(1, 0, ind - 1);
        cout << "Case " << tc++ << ":" << endl;
        cin >> Q, q = 1;
        while (Q--) {
            cin >> c >> a >> b;
            if (c == 'F' || c == 'E' || c == 'I') update(1, 0, ind - 1, a, b, c);
            else if (c == 'S') cout << "Q" << q++ << ": " << query(1, 0, ind - 1, a, b) << endl;
        }
    }
    return 0;
}
