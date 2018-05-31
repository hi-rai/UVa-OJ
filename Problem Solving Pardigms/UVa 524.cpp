#include<bits/stdc++.h>
using namespace std;

int soln[20], n;
bitset<50> prime;
bitset<20> used;

void solve(int t) {
    if(t == n + 1) {
        if(prime[soln[1] + soln[n]] == false)   return;
        for(int i = 1; i <= n; i++) {
            cout << soln[i];
            if (i != n) cout << " ";
        }
        cout << endl;
        return;
    }
    for(int i = (t % 2 ? 3 : 2); i < n + 1; i += 2)
        if(!used[i] && prime[i + soln[t - 1]]) {
            used[i] = true, soln[t] = i;
            solve(t + 1);
            used[i] = false;
        }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int tc = 1;
    prime.reset(), prime[2] = true;
    for(int i = 3; i < 40; i += 2) {
        prime[i] = true;
        for (int j = 2; j < i / 2; j++)
            if (i % j == 0) prime[i] = false;
    }
    while (cin >> n) {
        if(tc != 1) cout << endl;
        cout << "Case " << tc++ << ":" << endl;
        used.reset(), soln[1] = 1, used[1] = true;
        solve(2);
    }
    return 0;
}
