//Find the lcm of all possible four pairs and then take the best possible value for the required minimum and maximum value, by
//dividing the table length by the obtained lcm. Take care whether you have to take floor or ceiling

#include<bits/stdc++.h>
using namespace std;

int n, t, ind, lc[50][50], coin[50], table[12], val[230500];

int gcd(int a,int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a,int b) {
    return a * (b / gcd(a, b));
}
int lcm2(int i,int j) {
    return lc[i][j] = coin[i] * (coin[j] / gcd(coin[i], coin[j]));
}
int lcm4(int i,int j,int k,int l) {
    int x, y;
    x = (lc[i][j] == -1 ? lcm2(i, j) : lc[i][j]);
    y = (lc[k][l] == -1 ? lcm2(k, l) : lc[k][l]);
    return lcm(x, y);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> t, n) {
        memset(lc, -1, sizeof lc);
        ind = 0;
        for (int i = 0; i < n; i++)
            cin >> coin[i];
        for (int i = 0; i < t; i++)
            cin >> table[i];
        for (int i = 0; i < n - 3; i++)
            for (int j = i + 1; j < n - 2; j++)
                for (int k = j + 1; k < n - 1; k++)
                    for (int l = k + 1; l < n; l++)
                        val[ind++] = lcm4(i, j, k, l);
        for (int i = 0; i < t; i++) {
            int mx = INT_MAX, mn = INT_MIN;
            for (int k = 0; k < ind; k++) {
                float temp = table[i] / ((float) val[k]);
                mn = max(mn, (int) (floor(temp) * val[k]));
                mx = min(mx, (int) (ceil(temp) * val[k]));
            }
            cout << mn << " " << mx << endl;
        }
    }
    return 0;
}
