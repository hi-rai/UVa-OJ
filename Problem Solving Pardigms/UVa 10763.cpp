#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, t, u, p, q;
    vector<pii> a, b;
    while (cin >> n, n) {
        a.clear(), b.clear(), p = q = 0;
        for (int i = 0; i < n; i++) {
            cin >> t >> u;
            if (t > u) b.push_back(pii(t, u)), p++;
            else a.push_back(pii(u, t)), q++;
        }
        if (p != q) cout << "NO" << endl;
        else {
            sort(a.begin(), a.end()), sort(b.begin(), b.end());
            int ans = 1;
            for (int i = 0; i < p && ans; i++)
                if (a[i] != b[i]) ans = 0;
            cout << (ans ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
