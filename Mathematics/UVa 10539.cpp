//Easy problem
//First create a list of primes upto 10^6 using sieve of erastosthenes and then calculate the number of strict multiples of
//the primes calculated that lies in the range given

#include<bits/stdc++.h>
#define SIEVE_SIZE 1000005
using namespace std;

bitset<SIEVE_SIZE> bs;
vector<int> primes;
long long TC, l, r, ans;

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
    cin >> TC;
    sieve();
    while (TC--) {
        cin >> l >> r;
        ans = 0;
        for (int i = 0, n = primes.size(); i < n; i++) {
            long long x = primes[i], y = x * x;
            if (y > r) break;
            while (y < l) y *= x;
            while (y <= r) y *= x, ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
