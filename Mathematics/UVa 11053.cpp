//An easy application of Floyd Cycle Finding algorithm

#include<bits/stdc++.h>
using namespace std;

int N, a, b;

int f(int x) {
    return ((a * (((long long)(x) * x) % N)) % N  + b) % N;
}

int cycleFind() {
    int tort = f(0), hare = f(f(0)), cyc_length = 1;
    while (tort != hare) tort = f(tort), hare = f(f(hare));
    hare = 0;
    while (tort != hare) hare = f(hare), tort = f(tort);
    tort = f(hare);
    while(tort != hare) cyc_length++, tort = f(tort);
    return N - cyc_length;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> N >> a >> b, N)
        cout << cycleFind() << endl;
    return 0;
}
