//To cancel the remainder between two numbers, take the difference of two terms and find the GCD of the remaining sequence.
//Also, we can use the absolute value, because if (a - b) is negative then (b - a) is positive

#include<bits/stdc++.h>
using namespace std;
int arr[1005];

int gcd(int x,int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int gcd_arr(int i,int j) {
    if (i == j) return arr[i];
    int temp = (i + j) / 2;
    return gcd(gcd_arr(i, temp), gcd_arr(temp + 1, j));
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, ind;
    while (cin >> x, x) {
        ind = 0;
        while (cin >> y, y)
            arr[ind++] = abs(y - x);
        cout << gcd_arr(0, ind - 1) << endl;
    }
    return 0;
}
