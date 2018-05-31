#include<bits/stdc++.h>
using namespace std;

int TC, a[505], book[505], n, k;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> n >> k;
        long long l = 0, h = 0, m;
        for(int i = 0; i < n; i++)
            cin >> a[i], h += a[i], l = max(a[i], (int)l);
        for(int i = 0; i < 50; i++) {
            m = (l + h) / 2;
            long long p = 0, s = 0;
            for(int j = 0; j < n; j++) {
                if(p + a[j] > m) s++, p = a[j];
                else p += a[j];
            }
            if(s < k)   h = m;
            else l = m + 1;
        }
        long long s = 1, p = 0;
        for(int i = n - 1; i >= 0; i--) {
            if (p + a[i] <= m) book[i] = s, p += a[i];
            else book[i] = ++s, p = a[i];
        }
        while(s != k) {
            for(int i = 0; i < n - 1; i++) {
                if (book[i] != book[i + 1]) book[i]++;
                else { book[i]++; break; }
            }
            ++s;
        }
        cout << a[0];
        for(int i = 1; i < n; i++) {
            if(book[i] == book[i - 1])  cout << " " << a[i];
            else cout << " / " << a[i];
        }
        cout << endl;
    }
    return 0;
}
