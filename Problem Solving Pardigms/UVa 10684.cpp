#include<bits/stdc++.h>
#define SZ 10005
using namespace std;

int arr[SZ], n;

int MaxSum1D(int n) {
    int sum = 0, ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        ans = max(ans, sum);
        sum = max(0, sum);
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while(cin >> n, n) {
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int t = MaxSum1D(n);
        if(t > 0) cout << "The maximum winning streak is " << t << "." << endl;
        else cout << "Losing streak." << endl;
    }
    return 0;
}
