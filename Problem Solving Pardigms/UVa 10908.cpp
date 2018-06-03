#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string str[105];
    int TC, M, N, Q, R, C;
    cin >> TC;
    while (TC--) {
        cin >> M >> N >> Q;
        for (int i = 0; i < M; i++)
            cin >> str[i];
        cout << M << " " << N << " " << Q << endl;
        for (int i = 0; i < Q; i++) {
            cin >> R >> C;
            int ans = 1;
            char ch = str[R][C];
            for (; R + ans < M && R - ans >= 0 && C - ans >= 0 && C < N; ans++) {
                bool chk = true;
                for (int x = 0, y = 2 * ans + 1; x < y && chk; x++) {
                    if (str[R - ans + x][C - ans] != ch) chk = false;
                    if (str[R - ans + x][C + ans] != ch) chk = false;
                    if (str[R - ans][C - ans + x] != ch) chk = false;
                    if (str[R + ans][C - ans + x] != ch) chk = false;
                }
                if (!chk) break;
            }
            cout << 2 * ans - 1 << endl;
        }
    }
    return 0;
}
