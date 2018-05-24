#include<bits/stdc++.h>
using namespace std;

int temp[10], tc = 1, tot, TC, l, r;
vector<int> kap;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i < 40001; i++) {
        int ind = 0, k = i * i;
        while (k) temp[ind++] = k % 10, k /= 10;
        for (k = ind - 1; k >= 0 ; k--) {
            int l = 0, h = 0, t = ind - 1;
            while (t >= k) l *= 10, l += temp[t--];
            while (t >= 0) h *= 10, h += temp[t--];
            if (l + h == i && l && h) {
                kap.push_back(i);
                break;
            }
        }
    }
    tot = kap.size();
    cin >> TC;
    while (TC--) {
        cin >> l >> r;
        int t = lower_bound(kap.begin(), kap.end(), l) - kap.begin(), check = 0;
        cout << "case #" << tc++ << endl;
        if (t == tot) cout << "no kaprekar numbers" << endl, check = 1;
        else while (t < tot && kap[t] <= r) cout << kap[t++] << endl, check = 1;
        if(!check) cout << "no kaprekar numbers" << endl;
        if (TC) cout << endl;
    }
    return 0;
}
