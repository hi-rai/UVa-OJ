#include<bits/stdc++.h>
#define SZ 20005
using namespace std;

int arr[SZ], TC, tc = 1, s, a, b;

int MaxSum1D(int n) {
    int sum = 0, ans = INT_MIN, st = 1;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(ans < sum) ans = sum, a = st, b = i + 2;
        else if(ans == sum && i + 2 - st > b - a) a = st, b = i + 2;
        if(sum < 0) sum = 0, st = i + 2;
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
    cin >> TC;
    while (TC--) {
        cin >> s;
        for(int i = 0; i < s - 1; i++)
            cin >> arr[i];
        if(MaxSum1D(s - 1) > 0) cout << "The nicest part of route " << tc++ << " is between stops " << a << " and " << b << endl;
        else cout << "Route " << tc++ << " has no nice parts" << endl;
    }
    return 0;
}
