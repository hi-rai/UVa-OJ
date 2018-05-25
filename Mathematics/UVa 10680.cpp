#include<bits/stdc++.h>
#define SIEVE_SIZE 1000005
using namespace std;

bitset<SIEVE_SIZE> bs;
vector<int> primes;
void sieve() {
    bs.set();
    bs[0] = bs[1] = false;
    for(long long i = 2; i < SIEVE_SIZE; i++)
        if(bs[i]) {
            for(long long j = i * i; j < SIEVE_SIZE; j += i) bs[j] = false;
            primes.push_back(i);
        }
    return;
}


int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    long long n, a, b, ans, inda, indb;
    while (cin >> n, n) {
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        ans = 1, a = 2, b = 5, inda = 0, indb = 0;
        while (a <= n) inda++, a *= 2;
        while (b <= n) indb++, b *= 5;
        inda -= (indb + 1), inda %= 4, a = 2;
        while (inda--) a *= 2;
        ans *= a;
        for (int i = 0; primes[i] <= n; i++) {
            if (primes[i] == 2 || primes[i] == 5) continue;
            inda = 0, a = primes[i];
            while (a <= n) inda++, a *= primes[i];
            inda--, inda %= 4, a = primes[i] % 10, b = a;
            while (inda--) a *= b;
            ans *= a, ans %= 10;
        }
        cout << ans << endl;
    }
    return 0;
}
