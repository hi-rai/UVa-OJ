#include<bits/stdc++.h>
using namespace std;

char c1, c2;
int a[55][55], b[55][55], prv[55], nxt[55];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> c1 >> c2, c1 != '#') {
        memset(prv, 0, sizeof prv);
        memset(nxt, 0, sizeof nxt);
        a[0][0] = 1, a[0][1] = (int) c1, b[0][1] = (int) c2, prv[0] = -1, nxt[0] = 1;
        for (int i = 1; i < 52; i++)
            cin >> c1 >> c2, a[i][0] = 1, a[i][1] = (int) c1, b[i][1] = (int) c2, prv[i] = i - 1, nxt[i] = i + 1;
        while (true) {
            int i = 1, t;
            for (; i < 52; i++) {
                if (a[i][0] == 0) continue;
                t = prv[i], t = (t >= 0 ? prv[t] : -1), t = (t >= 0 ? prv[t] : -1);
                if (t >= 0 && (a[i][a[i][0]] == a[t][a[t][0]] || b[i][a[i][0]] == b[t][a[t][0]])) break;
                t = prv[i];
                if (t >= 0 && (a[i][a[i][0]] == a[t][a[t][0]] || b[i][a[i][0]] == b[t][a[t][0]])) break;
            }
            if (i == 52) break;
            a[t][0]++, a[t][a[t][0]] = a[i][a[i][0]], b[t][a[t][0]] = b[i][a[i][0]], a[i][0]--;
            if (a[i][0] == 0) {
                if (prv[i] >= 0) nxt[prv[i]] = nxt[i];
                if (nxt[i] < 52) prv[nxt[i]] = prv[i];
            }
        }
        int cnt = 0;
        for (int i = 0; i < 52; i++)
            if (a[i][0]) cnt++;
        cout << cnt << (cnt == 1 ? " pile" : " piles") << " remaining: ";
        for (int i = 0, j = 0; i < 52; i++)
            if (a[i][0]) {
                cout << a[i][0], j++;
                if (j != cnt) cout << " ";
            }
        cout << endl;
    }
    return 0;
}
