#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC, n, m, a, g, c, cnt;
    string str[105];
    pii unsort[105];
    cin >> TC;
    while(TC--) {
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            cin >> str[i];
            a = c = g = cnt = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(str[i][j] == 'T')   cnt += a, cnt += g, cnt += c;
                else if(str[i][j] == 'G')  g++, cnt += a, cnt += c;
                else if(str[i][j] == 'C')  c++, cnt += a;
                else if(str[i][j] == 'A')  a++;
            }
            unsort[i] = pii(cnt, i);
        }
        sort(unsort, unsort + m);
        for(int i = 0; i < m; i++)
            cout << str[unsort[i].second] << endl;
        if(TC)  cout << endl;
    }
    return 0;
}
