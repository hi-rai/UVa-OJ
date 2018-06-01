#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int N, Q, a[50004], t;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> t;
        int l = lower_bound(a, a + N, t) - a;
        int h = upper_bound(a, a + N, t) - a;
        if(l == 0)  cout << "X ";
        else cout << a[l - 1] << " ";
        if(h > N - 1) cout << "X" << endl;
        else cout << a[h] << endl;
    }
    return 0;
}
