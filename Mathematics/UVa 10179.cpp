//basic application of euler's phi (totent) funciton

#include<bits/stdc++.h>
#define SIEVE_SIZE 100005
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

int eulerPhi(int x) {
    int ind = 0, ans = x, PF = primes[ind];
    while(PF * PF <= x) {
        if(x % PF == 0) ans -= ans / PF;
        while(x % PF == 0)  x /= PF;
        PF = primes[++ind];
    }
    if(x != 1)  ans -= ans / x;
    return ans;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    while (cin >> n, n)
        cout << eulerPhi(n) << endl;
    return 0;
}
