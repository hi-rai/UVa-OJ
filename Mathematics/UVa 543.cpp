//An easy problem

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
    int n;
    while (cin >> n, n) {
        for (auto i:primes)
            if (bs[i] && bs[n - i]) {
                cout << n << " = " << i << " + " << n - i << endl;
                break;
            }
    }
    return 0;
}
