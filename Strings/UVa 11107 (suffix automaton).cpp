#include<bits/stdc++.h>
#define SZ 100010
using namespace std;

struct state {
    int len, link, isClone, firstpos;
    map<char, int> trans;
};

state sa[2 * SZ];
int last, sz, cnt[2 * SZ], anslen, n, tc = 1;
string str, T;
set<string> ans;
bitset<130> bs[2 * SZ];

void sa_init() {
    last = 0, sz = 1;
    sa[0].isClone = 0, sa[0].firstpos = -1;
    sa[0].link = -1, sa[0].len = 0;
    for (int i = 0; i < 2 * SZ; i++)
        sa[i].trans.clear();
}

void sa_extend(char c) {
    int cur = sz++, p;
    sa[cur].len = sa[last].len + 1, sa[cur].isClone = 0, sa[cur].firstpos = sa[last].len;
    for (p = last; p != -1 && sa[p].trans.count(c) == 0; p = sa[p].link)
        sa[p].trans[c] = cur;
    if (p == -1) sa[cur].link = 0;
    else {
        int q = sa[p].trans[c];
        if (sa[p].len + 1 == sa[q].len) sa[cur].link = q;
        else {
            int clone = sz++;
            sa[clone].trans = sa[q].trans, sa[clone].link = sa[q].link, sa[clone].isClone = 1;
            sa[clone].len = sa[p].len + 1, sa[cur].link = sa[q].link = clone, sa[clone].firstpos = sa[q].firstpos;
            while (p != -1 && sa[p].trans[c] == q) sa[p].trans[c] = clone, p = sa[p].link;
        }
    }
    last = cur;
}

void dfs(int x) {
    if (cnt[x] != -1) return;
    cnt[x] = 0;
    for (auto t : sa[x].trans) {
        if (t.first > 'z' || t.first < 'a') {
            if (!bs[x][t.first])
                bs[x][t.first] = true, cnt[x]++;
        } else {
            dfs(t.second);
            for (int i = 0, m = (n > 96 ? 130 : n + 1); i < m; i++)
                if (bs[t.second][i] && !bs[x][i])
                    bs[x][i] = true, cnt[x]++;
        }
    }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> n, n) {
        if(tc != 1) cout << endl;
        else tc++;
        T = "";
        for (int i = 0; i < n; i++) {
            cin >> str;
            T += str, T += ((char)(i + 1) >= 'a' ? (char)('z' + i - 'a' + 2) : (char)(i + 1));
        }
        sa_init();
        for (auto c : T) sa_extend(c);
        memset(cnt, -1, sizeof cnt);
        for (int i = 0; i < sz; i++) bs[i].reset();
        dfs(0), anslen = 0, ans.clear();
        for (int i = 1; i < sz; i++)
            if(cnt[i] > n / 2 && sa[i].len > anslen)
                anslen = sa[i].len;
        for (int i = 1; i < sz; i++)
            if(cnt[i] > n / 2 && sa[i].len == anslen)
                ans.insert(T.substr(sa[i].firstpos - sa[i].len + 1, sa[i].len));
        if(ans.empty()) cout << "?" << endl;
        else for(auto &t : ans) cout << t << endl;
    }
    return 0;
}
