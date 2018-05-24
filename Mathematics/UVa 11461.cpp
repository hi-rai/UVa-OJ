#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[400], a, b;
    for (int i = 0; i < 400; i++)
        arr[i] = i * i;
    while (cin >> a >> b, a && b) {
        int t = lower_bound(arr, arr + 400, a) - arr;
        int u = upper_bound(arr, arr + 400, b) - arr;
        cout << u - t << endl;
    }
    return 0;
}
