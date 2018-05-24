//since this problem requires the calculation of euler's phi for many values, we will use modified euler phi function, which is
//fast for such cases

#include<bits/stdc++.h>
using namespace std;

const int SZ = 50005;
int euPhi[SZ], sum[SZ], n;
void modEulerPhi() {
    memset(euPhi, 0, sizeof euPhi);
    for(int i = 2; i < SZ; i++) euPhi[i] = i;
    for(int i = 2; i < SZ; i++)
        if(euPhi[i] == i)
            for(int j = i; j < SZ; j += i)
                euPhi[j] -= euPhi[j] / i;
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    modEulerPhi(), sum[0] = 0;
    for(int i = 0; i < SZ; i++)
        sum[i] = sum[i - 1] + euPhi[i];
    while (cin >> n, n)
        cout << sum[n] * 2 + 1 << endl;
    return 0;
}
