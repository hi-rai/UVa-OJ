#include<bits/stdc++.h>
#define SZ 550000
using namespace std;

int TC, memo[SZ][21], d, k;
bitset<2 * SZ> flg;

void calc(int d, int t, int ind) {
    if(d > 20) return;
    memo[t][d] = ind;
    if(flg[ind]) flg[ind] = false, calc(d + 1, t, 2 * ind + 1);
    else flg[ind] = true, calc(d + 1, t, 2 * ind);
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    flg.reset();
    for(int j = 1; j < 524289; j++)
        calc(1, j, 1);
    cin >> TC;
    while(TC--)
        cin >> d >> k, cout << memo[k][d] << endl;
    return 0;
}
