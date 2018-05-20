//Use of Catalan Numbers. Use the recursive definition to find the successive Catalan's Numbers. Then find the answer as fact(n)* Cat(n)
//Use custom functions to perform arithematic operations

#include<bits/stdc++.h>
using namespace std;

int arr[305][800], in[10000], n, done[305];

void multiply(int x, int y) {
    int carry, t = 0;
    for (int i = 0; i < 800; i++) {
        t = arr[x][i] * y + t;
        arr[x][i] = t % 10;
        t /= 10;
    }
    return;
}

void divide(int x, int y) {
    int t = 0;
    for (int i = 199; i >= 0; i--) {
        t = t * 10 + arr[x][i];
        arr[x][i] = t / y, t %= y;
    }
    return;
}

void assign(int x, int y) {
    for (int i = 0; i < 200; i++)
        arr[x][i] = arr[y][i];
    return;
}

void prnt(int x) {
    int i = 799;
    while (arr[x][i] == 0 && i >= 0) i--;
    if (i == -1) cout << 0;
    else while (i >= 0) cout << arr[x][i], i--;
    cout << endl;
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(arr, 0, sizeof arr);
    memset(done, 0, sizeof done);
    int i = 0, m = -1;
    while (cin >> n, n) in[i++] = n, m = max(m, n);
    arr[0][0] = 1;
    for (int j = 0; j < m; j++)
        assign(j + 1, j), multiply(j + 1, 2 * (2 * j + 1)), divide(j + 1, j + 2);
    for (int j = 0; j < i; j++) {
        int x = in[j];
        if (done[in[j]] == 0) {
            while (x) multiply(in[j], x--);
            done[in[j]] = 1;
        }
        prnt(in[j]);
    }
    return 0;
}
