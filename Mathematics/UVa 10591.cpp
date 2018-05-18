//An easy application of Floyd Cycle Finding Algorithm

#include<bits/stdc++.h>
using namespace std;

int N, TC, in_value_index, cyc_length, tc = 1;

int f(int x) {
    int ans = 0, t;
    if(x < 0)   return -1;
    while (x) {
        t = x % 10, x /= 10;
        ans += t * t;
    }
    return (ans == 1 ? -1 : ans);
}

bool cycleFind(int x) {
    int tort = f(x), hare = f(f(x));
    if (tort < 0 || hare < 0) return false;
    while (tort != hare) {
        tort = f(tort), hare = f(f(hare));
        if (tort < 0 || hare < 0) return false;
    }
    return true;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> N;
        cout << "Case #" << tc++ << ": " << N;
        if (cycleFind(N)) cout << " is an Unhappy number.\n";
        else cout << " is a Happy number.\n";
    }
    return 0;
}
