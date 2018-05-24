//the prolem can be solved by brute force checking. However for calculation of (a^n mod n) dont use O(n) algorithm, it can be done
//in O(logn).
//Also, note that there are only 15 Carmichael numbers within the range given, so you can actually precalculate them and 
//check them with a simple statement.
//561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973.

#include<bits/stdc++.h>
#define SIEVE_SIZE 66000
using namespace std;

bitset<SIEVE_SIZE> bs;
vector<int> primes;
int n, ans;
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

bool chk(long long a, long long n) {
    long long res = 1, m = n, b = a;
    while (m) {
        if (m & 1) res = (res * a) % n;
        a = (a * a) % n, m >>= 1;
    }
    return res == b;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    while (cin >> n, n) {
        ans = (!bs[n]);
        if (ans) {
            for (int i = 2; i < n && ans; i++)
                ans = chk(i, n);
        }
        if (ans) cout << "The number " << n << " is a Carmichael number.\n";
        else cout << n << " is normal.\n";
    }
    return 0;
}
