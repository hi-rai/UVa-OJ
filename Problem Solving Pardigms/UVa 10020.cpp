//Interval covering problem - sort the points on the basis of their first coordinate and then on the basis of the second coordinate
//then choose the first interval which includes 0 and goes as right as possible. After this for each previously selected interval
//choose the next interval which starts to the left of the rightmost point of the previous and goes as much right as possibl, then
//include it and continue until the interval is covered or no other interval is left to continue

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
pii arr[100005];
vector<pii> ans;
int TC, a, b, M, ind, s, e;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> M;
        ind = s = e = 0;
        while (cin >> a >> b, a || b) {
            arr[ind++] = pii(a, b);
            if (a <= 0 && 0 < b) s = 1;
            if (a < M && M <= b) e = 1;
        }
        if (!s || !e) {
            cout << 0 << endl;
            if (TC) cout << endl;
            continue;
        }
        sort(arr, arr + ind), ans.clear();
        int i = 1, t = 0, j = 0;
        while (i < ind && arr[i].first <= 0) {
            if (arr[i].second >= arr[j].second) j = i;
            i++;
        }
        ans.push_back(arr[j]);
        while (i < ind && ans[t].second < M) {
            while (i < ind && arr[i].first <= ans[t].second) {
                if (arr[j].second < arr[i].second) j = i;
                i++;
            }
            if (arr[j].second == ans[t].second) break;
            ans.push_back(arr[j]), t++;
        }
        if (ans[t].second < M) {
            cout << 0 << endl;
            if (TC) cout << endl;
            continue;
        }
        cout << t + 1 << endl;
        for (int j = 0; j <= t; j++)
            cout << ans[j].first << " " << ans[j].second << endl;
        if (TC) cout << endl;
    }
    return 0;
}
