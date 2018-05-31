//Use two fenwick trees to check for zeroes in a range and to check the sign of the product

#include<bits/stdc++.h>
#define SZ 100005
#define p(x) ((x) & -(x))
using namespace std;

int ftzero[SZ], ftpos[SZ], arr[SZ], N, K, t, u;
char ch;

int sum(int ft[], int x) {
    int sum = 0;
    while(x > 0)  sum += ft[x], x -= p(x);
    return sum;
}

int increment(int ft[], int pos, int x){
    while(pos <= N) ft[pos] += x, pos += p(pos);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> N >> K) {
        memset(ftzero, 0, sizeof ftzero);
        memset(ftpos, 0, sizeof ftpos);
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            if (arr[i] == 0) increment(ftzero, i, 1);
            else if (arr[i] < 0) increment(ftpos, i, 1);
        }
        while (K--) {
            cin >> ch;
            if (ch == 'C') {
                cin >> t >> u;
                if (arr[t] == 0 && u != 0) {
                    increment(ftzero, t, -1);
                    if (u < 0) increment(ftpos, t, 1);
                } else if (arr[t] > 0 && u <= 0) {
                    if (u == 0) increment(ftzero, t, 1);
                    else increment(ftpos, t, 1);
                } else if (arr[t] < 0 && u >= 0) {
                    if (u == 0) increment(ftzero, t, 1);
                    increment(ftpos, t, -1);
                }
                arr[t] = u;
            } else {
                cin >> t >> u;
                if (sum(ftzero, u) != sum(ftzero, t - 1)) cout << 0;
                else if ((sum(ftpos, u) - sum(ftpos, t - 1)) % 2) cout << '-';
                else cout << '+';
            }
        }
        cout << endl;
    }
    return 0;
}
