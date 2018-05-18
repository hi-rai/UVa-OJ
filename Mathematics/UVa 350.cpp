//A straight forward application of Floyd Cycle Finding algorithm

#include<bits/stdc++.h>
using namespace std;

int Z, I, M, L, tc = 1;
pair<int, int> ans;
int f(int x) { return ((long long)Z * x + I) % M; }

pair<int, int> cycleFind() {
    int tort = f(L), hare = f(f(L)), in_value_index = 0, cyc_length = 1;
    while(tort != hare) tort = f(tort), hare = f(f(hare));
    hare = L;
    while(tort != hare) hare = f(hare), tort = f(tort), in_value_index++;
    tort = f(hare);
    while(tort != hare) cyc_length++, tort = f(tort);
    return make_pair(in_value_index, cyc_length);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> Z >> I >> M >> L, Z || I || M || L) {
        ans = cycleFind();
        cout << "Case " << tc++ << ": " << ans.second << endl;
    }
    return 0;
}
