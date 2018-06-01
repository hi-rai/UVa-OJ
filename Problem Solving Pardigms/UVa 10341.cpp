#include<bits/stdc++.h>
#define f1(x) (p * exp(-(x)) + r * cos(x) + u)
#define f2(x) (-q * sin(x) - s * tan(x) - t * (x) * (x))
using namespace std;

double p, q, r, s, t, u;

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while(cin >> p >> q >> r >> s >> t >> u) {
        if(p + r + u < 0 || f1(1) > f2(1))  cout << "No solution" << endl;
        else {
            double l = 0, h = 1, m, a, b;
            for(int i = 0; i < 50; i++) {
                m = (l + h) / 2, a = f1(m), b = f2(m);
                if(a > b)   l = m;
                else h = m;
            }
            cout << fixed << setprecision(4) << m << endl;
        }
    }
}
