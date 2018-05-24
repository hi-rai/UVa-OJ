//with a bit of planning the problem is easy and can be solved by brute force

#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int> > frac;

int gcd(int x,int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j < i; j++)
            if (gcd(i, j) == 1) frac.push_back(make_pair(j, i));
    frac.push_back(make_pair(1, 1));
    sort(frac.begin(), frac.end(), [](pair<int, int> &x, pair<int, int> &y) {
        return x.first * y.second < x.second * y.first;
    });
    while (cin >> n >> k) {
        int ind = 0, x, y;
        for (auto i : frac) {
            if (i.second <= n) ind++;
            if (ind == k) {
                x = i.first, y = i.second;
                break;
            }
        }
        cout << x << "/" << y << endl;
    }
    return 0;
}
