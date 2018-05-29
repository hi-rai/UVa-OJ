//finding longest common subsequence

#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int memo[110][110], m, ch, n, t;
string A[110], B[110];
vector<int> ans;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while(cin >> A[0]) {
        m = 1, n = 0, ch = 0;
        while(cin >> A[m], A[m][0] != '#') m++;
        while(cin >> B[n], B[n][0] != '#') n++;
        memset(memo, 0, sizeof memo);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) {
            if(A[i - 1] == B[j - 1]) t = memo[i - 1][j - 1] + 1;
            else t = -INF;
            memo[i][j] = max(t, max(memo[i - 1][j], memo[i][j - 1]));
        }
        ans.clear();
        int r = m, c = n;
        while(r > 0 && c > 0) {
            if(memo[r][c] == memo[r - 1][c - 1] + 1  && A[r - 1] == B[c - 1])    ans.push_back(r - 1), r -= 1, c -= 1;
            else if(memo[r - 1][c] == memo[r][c]) r -= 1;
            else c -= 1;
        }
        reverse(ans.begin(), ans.end());
        for(auto t : ans) {
            if(ch) cout << " ";
            else ch++;
            cout << A[t];
        }
        cout << endl;
    }
    return 0;
}
