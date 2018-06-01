#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, h[20005], k[20005];
    while(cin >> n >> m, n && m) {
        for(int i = 0; i < n; i++)  cin >> h[i];
        for(int i = 0; i < m; i++)  cin >> k[i];
        if(n > m) {
            cout << "Loowater is doomed!" << endl;
            continue;
        }
        sort(h, h + n), sort(k, k + m);
        int a = lower_bound(k, k + m, h[0]) - k;
        if(m - a < n) cout << "Loowater is doomed!" << endl;
        else {
            int ch = 1, ans = 0;
            for(int i = 0, j = a; i < n && ch; i++, j++) {
                while(j < m && h[i] > k[j]) j++;
                ans += k[j];
                if(j == m)  ch = 0;
            }
            if(ch) cout << ans << endl;
            else cout << "Loowater is doomed!" << endl;
        }
    }
    return 0;
}
