//Easy question of finding the number of prime factors

#include<bits/stdc++.h>
#define SIEVE_SIZE 1100
using namespace std;

bitset<SIEVE_SIZE> bs;
vector<int> primes;
int n, m = 0, tot = 0, M[1000006], mu[1000006], in[1005];

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

int calc(int x) {
    int ind = 0, PF = primes[ind], cnt = 0;
    while (PF * PF <= x) {
        if (x % PF == 0) {
            x /= PF, cnt++;
            if (x % PF == 0) return 0;
        }
        PF = primes[++ind];
    }
    if (x != 1) cnt++;
    return (cnt & 1 ? -1 : 1);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    while (cin >> n, n) in[tot++] = n, m = max(n, m);
    mu[1] = 1, M[1] = 1;
    for (int i = 2; i <= m; i++)
        mu[i] = calc(i), M[i] = M[i - 1] + mu[i];
    for (int i = 0; i < tot; i++)
        cout << setw(8) << in[i] << setw(8) << mu[in[i]] << setw(8) << M[in[i]] << endl;
    return 0;
}
