#include<bits/stdc++.h>
using namespace std;

map<string, int> ind;
int regd[10005], cnt[105];
string prj[105];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string st, sheet = "1";
    while (sheet == "1") {
        memset(cnt, 0, sizeof cnt);
        int k = 0, p = 0;
        getline(cin, sheet);
        while (isupper(sheet[0])) {
            prj[p] = sheet;
            getline(cin, st);
            while (islower(st[0])) {
                if (ind.count(st) == 0) ind[st] = k++, regd[k - 1] = p, cnt[p]++;
                else {
                    int t = ind[st];
                    if (regd[t] != -1 && regd[t] != p) cnt[regd[t]]--, regd[t] = -1;
                }
                getline(cin, st);
            }
            sheet = st, p++;
        }
        int odr[p + 5];
        for (int i = 0; i < p; i++)
            odr[i] = i;
        sort(odr, odr + p, [](int x, int y) {
            if (cnt[x] == cnt[y]) return prj[x] < prj[y];
            return cnt[x] > cnt[y];
        });
        for (int i = 0; i < p; i++)
            cout << prj[odr[i]] << " " << cnt[odr[i]] << endl;
        ind.clear();
    }
    return 0;
}
