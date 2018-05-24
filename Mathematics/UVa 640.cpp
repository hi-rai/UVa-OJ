#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bitset<1000005> bs;
    bs.reset();
    for (int i = 1; i < 1000001; i++) {
        if (!bs[i]) cout << i << endl;
        int k = i, s = 0;
        while (k) s += k % 10, k /= 10;
        bs[s + i] = true;
    }
    return 0;
}
