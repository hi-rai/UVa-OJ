#include<bits/stdc++.h>
using namespace std;

int TC, n, k;

int f(long long x) {
    x *= x;
    int t = (int) (log10(x) + 1);
    if (t > n) x /= (int) (pow(10.0, t - n));
    return (int) x;
}

int cycleFind() {
    int tort = f(k), hare = f(f(k)), cyc_length = 1, ans = k;
    while (tort != hare) { tort = f(tort), hare = f(f(hare)); }
    hare = k;
    while (tort != hare) ans = max(hare = f(hare), ans), tort = f(tort);
    ans = max(tort = f(hare), ans);
    while (tort != hare) cyc_length++, ans = max(tort = f(tort), ans);
    return ans;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> n >> k;
        cout << cycleFind() << endl;
    }
    return 0;
}
