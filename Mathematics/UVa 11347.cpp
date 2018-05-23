//Easy problem of finding the number of factors of a given number with some extra modifications

#include<bits/stdc++.h>
#define SIEVE_SIZE 1005
using namespace std;

map<int, int> ind;
bitset<SIEVE_SIZE> bs;
int fact[1005][200], TC, tc = 1;
string str;

void sieve() {
    bs.set(), ind.clear();
    bs[0] = 0, bs[1] = 0;
    for(int i = 2, k = 1; i < SIEVE_SIZE; i++)
        if(bs[i]) {
            for (int j = i * i; j < SIEVE_SIZE; j += i) bs[j] = 0;
        ind[i] = k++;
    }
    return;
}

void modifiedSieve() {
    memset(fact, 0, sizeof fact);
    for (int i = 2; i < 1001; i++)
        if (fact[i][0] == 0)
            for (int j = i; j < 1001; j += i) {
                int t = 0, p = j;
                while (p % i == 0) t++, p /= i;
                fact[j][0] += t, fact[j][ind[i]] += t;
            }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(), modifiedSieve();
    cin >> TC;
    while (TC--) {
        cin >> str;
        int n = 0, t = 0, dp[200];
        while (str[t] != '!') n *= 10, n += (int) (str[t] - '0'), t++;
        if (n == 1 || n == 0) {
            cout << "Case " << tc++ << ": 1\n";
            continue;
        }
        t = str.length() - t;
        memset(dp, 0, sizeof dp);
        for (int i = n; i > 0; i -= t) {
            for (int j = 0; j < 200; j++)
                dp[j] += fact[i][j];
        }
        long long ans = 1;
        for (int i = 1; i < 200; i++) {
            ans *= (dp[i] + 1);
            if (ans < 0 || ans > (long long) (1e18)) break;
        }
        cout << "Case " << tc++ << ": ";
        if (ans < 0 || ans > (long long) (1e18)) cout << "Infinity\n";
        else cout << ans << "\n";
    }
    return 0;
}
