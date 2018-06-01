#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int Y, P, p[100005];
    while(cin >> Y >> P) {
        for(int i = 0; i < P; i++)
            cin >> p[i];
        int ans = 0, f, l;
        for(int i = 0; i < P; i++) {
            int t = upper_bound(p + i, p + P, p[i] + Y - 1) - p - i;
            if(ans < t) ans = t, f = p[i], l = p[t + i - 1];
        }
        cout << ans << " " << f << " " << l << endl;
    }
    return 0;
}
