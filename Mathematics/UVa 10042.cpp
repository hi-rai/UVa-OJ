//easy problem

#include<bits/stdc++.h>
#define SIEVE_SIZE 32000
using namespace std;

bitset<SIEVE_SIZE> bs;
vector<int> primes;
vector<int> sumPrimes;
int TC, x;

int sumDig(int temp) {
    int sum = 0;
    while (temp) sum += temp % 10, temp /= 10;
    return sum;
}

void sieve() {
    bs.set();
    bs[0] = bs[1] = false;
    for(long long i = 2; i < SIEVE_SIZE; i++)
        if(bs[i]) {
            for(long long j = i * i; j < SIEVE_SIZE; j += i) bs[j] = false;
            primes.push_back(i), sumPrimes.push_back(sumDig(i));
        }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    cin >> TC;
    while (TC--) {
        cin >> x;
        while (x++) {
            if (x < SIEVE_SIZE && bs[x]) continue;
            int y = x, sum = 0;
            for (int i = 0; primes[i] <= sqrt(y); i++)
                while (y % primes[i] == 0) y /= primes[i], sum += sumPrimes[i];
            if (x == y) continue;
            if (y != 1) sum += sumDig(y);
            if (sum == sumDig(x)) break;
        }
        cout << x << endl;
    }
    return 0;
}
