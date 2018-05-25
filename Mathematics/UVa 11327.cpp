//question related to euler phi function

#include<bits/stdc++.h>
#define SIEVE_SIZE 1005
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

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    long long memo[200005], n;
    memo[0] = 0, memo[1] = 2;
    for(int i = 2; i < 200005; i++)
        memo[i] = memo[i - 1] + eulerPhi(i);
    while(cin >> n, n) {
        long long cnt = lower_bound(memo, memo + 200005, n) - memo, t = n - memo[cnt - 1], ind = 0, p = 0;
        for(int i = 0; i <= cnt && ind < t; i++)
            if(gcd(i, cnt) == 1)    ind++, p = i;
        cout << p << "/" << cnt << endl;
    }
    return 0;
}
