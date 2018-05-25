//The count of m, such that 1 <= m <= n and gcd(m,n) = m is the number of divisors of m
//Also, count of m, such that 1 <= m <= n and gcd(m,n) = 1, is the value of the euler phi function for n.
//Also, 1 is counted in both of the above
//So, the ans would be n - numDiv(n) - euPhi(n) + 1. n = 1 is a corner case so check your algorithm for it

#include<bits/stdc++.h>
#define SIEVE_SIZE 100005
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

long long eulerPhi(long long x) {
    if(x == 1)  return 1;
    long long ind = 0, ans = x, PF = primes[ind];
    while(PF * PF <= x) {
        if(x % PF == 0) ans -= ans / PF;
        while(x % PF == 0)  x /= PF;
        PF = primes[++ind];
    }
    if(x != 1)  ans -= ans / x;
    return ans;
}

long long divNum(long long x) {
    long long ind = 0, ans = 1, t, PF = primes[ind];
    while(PF * PF <= x)  {
        if(x % PF == 0) {
            t = 0;
            while(x % PF == 0) { x /= PF, t++; }
            ans *= (t + 1);
        }
        PF = primes[++ind];
    }
    if(x != 1)  ans *= 2;
    return ans;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    long long n;
    while(cin >> n) cout << n - eulerPhi(n) - divNum(n) + 1 << endl;
    return 0;
}
