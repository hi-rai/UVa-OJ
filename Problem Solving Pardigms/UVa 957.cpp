#include<bits/stdc++.h>
using namespace std;

string ans;
int sum[205][205], R, C;
char ch;
bitset<205> bs[205];

void prefixSum() {
    memset(sum, 0, sizeof sum);
    for(int i = 1; i <= R; i++)
        for(int j =1; j <= C; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + bs[i][j];
}

void BtoD(int lr, int lc, int rr, int rc) {
    int s = sum[rr][rc] + sum[lr - 1][lc - 1] - sum[rr][lc - 1] - sum[lr - 1][rc];
    if(s == (rr - lr + 1) * (rc - lc + 1))  ans += "1";
    else if(s == 0) ans += "0";
    else {
        ans += "D";
        int t = (lr + rr) / 2, u = (lc + rc) / 2;
        if(lr == rr) BtoD(lr, lc, lr, u), BtoD(lr, u + 1, lr, rc);
        else if(lc == rc) BtoD(lr, lc, t, lc), BtoD(t + 1, lc, rr, lc);
        else {
            BtoD(lr, lc, t, u);
            BtoD(lr, u + 1, t, rc);
            BtoD(t + 1, lc, rr, u);
            BtoD(t + 1, u + 1, rr, rc);
        }
    }
}

void DtoB(int lr, int lc, int rr, int rc) {
    cin >> ch;
    if(ch == '1' || ch == '0') {
        bool t = (ch == '1');
        for(int i = lr; i <= rr; i++)
            for(int j = lc; j <= rc; j++)
                bs[i][j] = t;
    } else {
        int t = (lr + rr) / 2, u = (lc + rc) / 2;
        if(lr == rr) DtoB(lr, lc, lr, u), DtoB(lr, u + 1, lr, rc);
        else if(lc == rc) DtoB(lr, lc, t, lc), DtoB(t + 1, lc, rr, lc);
        else {
            DtoB(lr, lc, t, u);
            DtoB(lr, u + 1, t, rc);
            DtoB(t + 1, lc, rr, u);
            DtoB(t + 1, u + 1, rr, rc);
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int Y, P, anslen, a[100005], t, f, l;
    while (cin >> Y >> P) {
        for(int i = 0; i < P; i++)
            cin >> a[i];
        anslen = 0;
        for(int i = 0; i < P; i++) {
            t = upper_bound(a, a + P, a[i] + Y - 1) - a, t--;
            if(t - i + 1 > anslen) anslen = t - i + 1, f = a[i], l = a[t];
        }
        cout << anslen << " " << f << " " << l << endl;
    }
    return 0;
}
