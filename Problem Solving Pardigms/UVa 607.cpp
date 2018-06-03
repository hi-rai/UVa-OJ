#include<bits/stdc++.h>
#define SZ 1005
using namespace std;

typedef pair<int, int> pii;
int memoL[SZ], memoDI[SZ], arr[SZ], n, L, c, tc = 1;

int calcDI(int x) {
    if(x == L) return 0;
    if(L - x <= 10) return -c;
    return (L - x - 10) * (L - x - 10);
}

pii calc(int t) {
    if (t == n) return pii(0, 0);
    if (memoL[t] != -1) return pii(memoL[t], memoDI[t]);
    int tL = INT_MAX, tDI;
    for (int i = t, s = 0; i < n; i++) {
        s += arr[i];
        if (s > L) break;
        pii temp = calc(i + 1);
        if (tL > temp.first) tL = temp.first, tDI = calcDI(s) + temp.second;
        else if (tL == temp.first) tDI = min(tDI, calcDI(s) + temp.second);
    }
    memoL[t] = tL + 1, memoDI[t] = tDI;
    return pii(memoL[t], memoDI[t]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> n, n) {
        cin >> L >> c;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        memset(memoL, -1, sizeof memoL);
        pii ans = calc(0);
        if(tc != 1) cout << endl;
        cout << "Case " << tc++ << ":" << endl;
        cout << "Minimum number of lectures: " << ans.first << endl;
        cout << "Total dissatisfaction index: " << ans.second << endl;
    }
    return 0;
}
