//first validate the input so that are represented using largest possible fibbonacci numbers
//Now, assume a is the sum. A digit by digit keep adding b to a. And after addition of each digit bring a to proper form.
//Two cases when one the current digit of a is 0 corresponding to digit of b which is 1. For this simply make that digit of a
//(which now is assumed to represent the sum) 1.
//The other case is when both are the digits are 1. For this the corner case has to be taken when the digit is at 1 and 2 position
//from left. For other cases, in a make next digit 1, and then recursively or iteratively add 1 to a at digit on the left at
//second position from the current digit.

#include<bits/stdc++.h>
using namespace std;

void validate(bitset<120>& a) {
    for (int j = 110; j > 0; j--) {
        int ind = j;
        while (a[ind] && a[ind - 1]) {
            a[ind] = a[ind - 1] = false, a[ind + 1] = true;
            ind += 2;
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bitset<120> a, b;
    bool check = true;
    while (cin >> a >> b) {
        if (check) check = false;
        else cout << "\n";
        validate(a), validate(b);
        for (int i = 100; i >= 0; i--)
            if (b[i]) {
                if (a[i] == false) {
                    a[i] = true;
                    int ind = i;
                    while (a[ind] == true) ind++;
                    ind--;
                    while (ind > 0 && a[ind] && a[ind - 1]) {
                        a[ind + 1] = true, a[ind] = a[ind - 1] = false;
                        int n = ind + 2;
                        while (a[n]) {
                            a[n] = a[n - 1] = false;
                            a[n + 1] = true, n += 2;
                        }
                        ind -= 2;
                    }
                } else {
                    int t = i;
                    while (true) {
                        if (t == 0) {
                            if (a[0]) a[1] = true, a[0] = false;
                            else a[0] = true;
                            break;
                        } else if (t == 1) {
                            if (a[1]) a[0] = a[2] = true, a[1] = false;
                            else a[1] = true;
                            break;
                        } else if (a[t] == true) {
                            a[t + 1] = true, a[t] = false;
                            t -= 2;
                        } else {
                            a[t] = true;
                            break;
                        }
                    }
                    validate(a);
                }
            }
        int ind = 119;
        while (ind >= 0 && a[ind] == false) ind--;
        if (ind == -1) cout << 0;
        while (ind >= 0) cout << a[ind--];
        cout << "\n";
    }
    return 0;
}
