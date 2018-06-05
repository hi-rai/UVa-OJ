#include<bits/stdc++.h>
using namespace std;

vector<int> seq, arr;
int n = 0, t;

int LIS(int n) {
    int l[n], s[n], len = 1;
    s[0] = arr[0], l[0] = 1;
    for(int i = 1; i < n; i++) {
        int t = lower_bound(s, s + len, arr[i]) - s;
        if(t == len) s[len++] = arr[i];
        else if(arr[i] < s[t]) s[t] = arr[i];
        l[i] = t + 1;
    }
    int p = INT_MAX, temp = len;
    seq.resize(len);
    for(int j = n - 1; j >= 0; j--)
        if(l[j] == temp && arr[j] <= p)
            seq[temp - 1] = arr[j], p = arr[j], temp--;
    return len;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> t) arr.push_back(t), n++;
    cout << LIS(n) << endl << '-' << endl;
    for (auto p : seq) cout << p << endl;
    return 0;
}
