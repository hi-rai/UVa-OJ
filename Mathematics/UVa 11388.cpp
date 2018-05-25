#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC, a, b;
    cin >> TC;
    while (TC--) {
        cin >> a >> b;
        if(a > b || b % a)  cout << -1 << endl;
        else cout << a << " " << b << endl;
    }
    return 0;
}
