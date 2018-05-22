//Calculate the number of prime factors distinct prime factors and their count, and use a bit of combinatorics to arrive at the 
//solution. Treat as special case when n = 1 when answer is 1 and when the number entered is prime, for which the answer is 2.

#include<bits/stdc++.h>
#define SIEVE_SIZE 100000
using namespace std;

bitset<SIEVE_SIZE> bs;
vector<int> primes;
int n;
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

long long calc(long long x) {
    int ind = 0, PF = primes[ind], t, ans = 0, ch = 0;
    while (PF * PF <= x) {
        if (x % PF == 0) {
            t = 0;
            while (x % PF == 0) x /= PF, t++;
            ans = ans * (2 * t + 1) + t;
            ch = 1;
        }
        PF = primes[++ind];
    }
    if (x != 1) ans = ans * 3 + 1;
    if(!ch) return 2;
    return ans + 1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    while (cin >> n, n) {
        if(n == 1) cout << "1 1" << endl;
        else cout << n << " " << calc(n) << endl;
    }
    return 0;
}
