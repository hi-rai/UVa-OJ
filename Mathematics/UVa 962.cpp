#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> cab;
    long long l, r;
    for (int i = 1; i < 1100; i++)
        for (int j = i + 1; j < 1100; j++)
            cab.push_back(i * i * i + j * j * j);
    sort(cab.begin(), cab.end());
    while (cin >> l >> r) {
        int t = lower_bound(cab.begin(), cab.end(), l) - cab.begin(), p = 0;
        while (cab[t] <= l + r) {
            int check = 0;
            while (cab[t] == cab[t + 1]) check = 1, t++;
            if (check) cout << cab[t] << endl, p = 1;
            t++;
        }
        if (p == 0) cout << "None\n";
    }
    return 0;
}
