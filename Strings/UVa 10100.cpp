#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int memo[1100][1100], m, n, t, tc = 1;
string A[1100], B[1100], x, y;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (getline(cin, x), getline(cin, y), cin) {
        cout << setw(2) << tc++ << ". ";
        if (x.empty() || y.empty()) { cout << "Blank!\n"; continue; }
        for(auto &p : x) if(!isalnum(p))    p = ' ';
        for(auto &p : y) if(!isalnum(p))    p = ' ';
        m = n = 0;
        stringstream inx, iny;
        inx << x; while(inx >> A[m]) m++;
        iny << y; while(iny >> B[n]) n++;
        memset(memo, 0, sizeof memo);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                if (A[i - 1] == B[j - 1]) t = memo[i - 1][j - 1] + 1;
                else t = -INF;
                memo[i][j] = max(t, max(memo[i - 1][j], memo[i][j - 1]));
            }
        cout << "Length of longest match: " << memo[m][n] << "\n";
    }
    return 0;
}
