//An easy problem

#include<bits/stdc++.h>
using namespace std;

int memo[1005][2600], n;

void calc() {
    memset(memo, 0, sizeof memo);
    memo[0][0] = memo[1][0] = 1;
    for (int i = 2; i < 1001; i++)
        for (int j = 0, carry = 0; j < 2600; j++) {
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
    while (cin >> n) {
        cout << n << "!" << endl;
        int t = 2599;
        while (!memo[n][t] && t >= 0) t--;
        for (; t >= 0; t--)
            cout << memo[n][t];
        cout << endl;
    }
    return 0;
}
