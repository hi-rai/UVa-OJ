//An application of Floyd Cycle Finding algorithm

#include<bits/stdc++.h>
using namespace std;

int step, mod;

int f(int x) {
    return (step + x) % mod;
}

bool cycleFind() {
    int tort = f(0), hare = f(f(0)), cyc_length = 1;
    while (tort != hare) tort = f(tort), hare = f(f(hare));
    hare = 0;
    while (tort != hare) hare = f(hare), tort = f(tort);
    tort = f(hare);
    while (tort != hare) cyc_length++, tort = f(tort);
    return cyc_length == mod ? true : false;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> step, !cin.eof()) {
        cin >> mod;
        cout << setfill(' ') << setw(10) << step;
        cout << setfill(' ') << setw(10) << mod;
        cout << "    ";
        if (cycleFind()) cout << "Good Choice\n\n";
        else cout << "Bad Choice\n\n";
    }
    return 0;
}
