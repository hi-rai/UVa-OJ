//maximum subset sum problem

#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC, n, sum, s, t, a[105];
    bitset<50004> memo;
    cin >> TC;
    while(TC--) {
        cin >> n;
        sum = 0, memo.reset();
        for(int i = 0; i < n; i++)
            cin >> a[i], sum += a[i];
        s = sum / 2, memo[0] = true, t = -1;
        for(int i = 0; i < n; i++)
            for(int j = s - 1; j >= 0; j--)
                if(memo[j] && j + a[i] <= s)
                    memo[j + a[i]] = true;
        for(int i = s; i >= 0 && t == -1; i--)
            if(memo[i]) t = i;
        cout << sum - 2 * t << endl;
    }
    return 0;
}
