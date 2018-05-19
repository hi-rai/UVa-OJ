//Use Floyd Cycle Finding algorithm to find a cycle if any, in this case the number will not be happy, in the sequence for a number 
//Else find the length of the happy sequence and then use optimisations to avoid recalculations

#include<bits/stdc++.h>
using namespace std;

int cnt[100005], happy[100005], L, H, chk = 0, tot;
vector<int> h;

int f(int x) {
    int ans = 0, t;
    if (x < 0) return -1;
    while (x) {
        t = x % 10, x /= 10;
        ans += t * t;
    }
    return ans == 1 ? -1 : ans;
}

void cycleFind(int x) {
    int tort = f(x), hare = f(f(x)), len = 2;
    if (tort < 0 || happy[tort] == 1) {
        cnt[x] = 1 + cnt[max(1, tort)], happy[x] = 1;
        h.push_back(x);
        return;
    } else if (hare < 0 || happy[hare] == 1) {
        cnt[x] = 2 + happy[max(1, hare)], cnt[tort] = -1 + cnt[x], happy[x] = happy[tort] = 1;
        h.push_back(tort), h.push_back(x);
        return;
    } else if (happy[tort] == 0 || happy[hare] == 0) {
        happy[tort] = happy[x] = 0;
        return;
    }
    while (tort != hare) {
        tort = f(tort), hare = f(f(hare));
        if (hare < 0) {
            int y = x, c = 0;
            while (y > 1) c++, y = f(y);
            happy[x] = 1, cnt[x] = ++c, y = f(x), h.push_back(x);
            while (y > 1) c--, happy[y] = 1, cnt[y] = c, h.push_back(y), y = f(y);
            return;
        }
        if (happy[tort] == 1) {
            len += cnt[tort];
            while (x != tort) happy[x] = 1, cnt[x] = len, h.push_back(x), x = f(x), len--;
            return;
        } else if (happy[tort] == 0) {
            while (x != tort) happy[x] = 0, x = f(x);
            return;
        } else len++;
    }
    hare = x;
    while (hare != tort) tort = f(tort), hare = f(hare);
    while (x != hare) happy[x] = 0, x = f(x);
    happy[hare] = 0, x = f(hare);
    while (x != hare) happy[x] = 0, x = f(x);
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(happy, -1, sizeof happy);
    happy[1] = 1, cnt[1] = 1, h.push_back(1);
    for (int i = 2; i < 100000; i++)
        if (happy[i] == -1) cycleFind(i);
    sort(h.begin(), h.end()), tot = h.size();
    while (cin >> L, !cin.eof()) {
        cin >> H;
        if (chk) cout << "\n";
        else chk = 1;
        int ind = lower_bound(h.begin(), h.end(), L) - h.begin();
        if(tot != ind)  while (ind < tot && h[ind] <= H) cout << h[ind] << " " << cnt[h[ind]] << endl, ind++;
    }
    return 0;
}
