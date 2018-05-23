//An easy problem

#include<bits/stdc++.h>
using namespace std;

int memo[370][800], cnt[10], n;

void calc() {
    memset(memo, 0, sizeof memo);
    memo[0][0] = memo[1][0] = 1;
    for (int i = 2; i < 370; i++)
        for (int j = 0, carry = 0; j < 800; j++) {
            int temp = memo[i - 1][j] * i + carry;
            memo[i][j] = temp % 10;
            carry = temp / 10;
        }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    calc();
    while (cin >> n, n) {
        cout << n << "! --" << endl;
        int t = 799;
        memset(cnt, 0, sizeof cnt);
        while (!memo[n][t] && t >= 0) t--;
        for (; t >= 0; t--)
            cnt[memo[n][t]]++;
        for (int i = 0; i < 10; i++) {
            cout << "    (" << i << ")" << setw(4) << cnt[i];
            if (i == 4) cout << endl;
        }
        cout << endl;
    }
    return 0;
}
