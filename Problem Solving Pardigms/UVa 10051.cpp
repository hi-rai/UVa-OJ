#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

string str[] = {"front", "back", "left", "right", "top", "bottom"};
int opp[] = {1, 0, 3, 2, 5, 4}, n, arr[505][6], tc = 1;
int posb[505][105], posc[505][105], ansl, ansp, ansc;
pii memo[505][105];
bitset<105> bs;

pii calc(int b, int c) {
    if (b >= n) return pii(0, -1);
    if (memo[b][c].first != -1) return memo[b][c];
    pii t = calc(b + 1, c), ret = {0, -1};
    if (t.first > ret.first) ret = t;
    for (int i = 0; i < 6; i++)
        if (arr[b][i] == c) {
            t = calc(b + 1, arr[b][opp[i]]);
            if (t.first + 1 > ret.first) ret = {t.first + 1, b}, posb[b][c] = t.second, posc[b][c] = i;
        }
    return memo[b][c] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> n, n) {
        bs.reset();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 6; j++)
                cin >> arr[i][j], bs[arr[i][j]] = true;
        memset(memo, -1, sizeof memo), ansl = 0;
        for (int i = 1; i <= 100; i++)
            if (bs[i]) {
                pii t = calc(0, i);
                if (t.first > ansl) ansl = t.first, ansp = t.second, ansc = i;
            }
        if(tc != 1) cout << endl;
        cout << "Case #" << tc++ << endl;
        cout << ansl << endl;
        while (ansl--) {
            cout << ansp + 1 << " " << str[posc[ansp][ansc]] << endl;
            int p = ansp;
            ansp = posb[ansp][ansc], ansc = arr[p][opp[posc[p][ansc]]];
        }
    }
    return 0;
}
