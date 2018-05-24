//To check whether the a number is the sum of two or more distinct terms use a bitset to store the possible sums of the currently
//entered numbers, and check if that number is already marked. Apart from that this problem is easy

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tot, TC = 1, n, p;
    bitset<1001> pres;
    while (cin >> tot) {
        bool check = true;
        p = 0, pres = 1;
        cout << "Case #" << TC++ << ": ";
        for (int i = 0; i < tot; i++) {
            cin >> n;
            if (i) cout << " ";
            cout << n;
            if (pres[n]) check = false;
            else if (check)
                for (int j = 1000; j >= 0; j--)
                    if (pres[j] && j + n <= 1000) pres[j + n] = 1;
            if (p >= n) check = false;
            else p = n;
        }
        cout << endl;
        cout << "This is " << (check ? "" : "not ") << "an A-sequence.\n";
    }
    return 0;
}
