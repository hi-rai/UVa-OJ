#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long k, l, h, s, kk, kl, kh, ks, n, tc = 1, p;
    while(cin >> n) {
        if(!n) {
            cout << setw(4) << tc++ <<". 0\n";
            continue;
        }
        p = k = n / 10000000, n %= 10000000;
        l = n / 100000, n %= 100000;
        h = n / 1000, n %= 1000;
        s = n / 100, n %= 100;
        kk = k / 10000000, k %= 10000000;
        kl = k / 100000, k %= 100000;
        kh = k / 1000, k %= 1000;
        ks = k / 100, k %= 100;
        cout << setw(4) << tc++ <<".";
        if(kk)  cout << " " << kk << " kuti";
        if(kl)  cout << " " << kl << " lakh";
        if(kh)  cout << " " << kh << " hajar";
        if(ks)  cout << " " << ks << " shata";
        if(k)   cout << " " << k;
        if(p)   cout << " kuti";
        if(l)   cout << " " << l << " lakh";
        if(h)   cout << " " << h << " hajar";
        if(s)   cout << " " << s << " shata";
        if(n)   cout << " " << n;
        cout << endl;
     }
    return 0;
}
