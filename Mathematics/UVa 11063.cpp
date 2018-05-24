//Don't forget to check for negative numbers

#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans, N, n, arr[105], tc = 1;
    bitset<20005> bs;
    while (cin >> N) {
        bs.reset(), n = 0, ans = 1;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (n >= arr[i] || arr[i] <= 0) ans = 0;
            if (ans) {
                for (int j = 0; j <= i && ans; j++) {
                    if (bs[arr[i] + arr[j]]) ans = 0;
                    else bs[arr[i] + arr[j]] = true;
                }
            }
            n = arr[i];
        }
        cout << "Case #" << tc++ << ": It is " << (ans ? "" : "not ") << "a B2-Sequence.\n\n";
    }
    return 0;
}
