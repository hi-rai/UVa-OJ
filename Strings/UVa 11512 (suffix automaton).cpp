//The problem has been solved using suffix automaton

#include<bits/stdc++.h>
#define SZ 1010
using namespace std;

struct state {
    int len, link, isClone, firstpos;
    map<char, int> trans;
};

state sa[2 * SZ];
int last, sz, len, anslen, ansind, TC, anscnt;
string T;

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
    for(p = last; p != -1 && sa[p].trans.count(c) == 0; p = sa[p].link)
        sa[p].trans[c] = cur;
    if(p == -1) sa[cur].link = 0;
    else {
        int q = sa[p].trans[c];
        if(sa[p].len + 1 == sa[q].len) sa[cur].link = q;
        else {
            int clone = sz++;
            sa[clone].trans = sa[q].trans, sa[clone].link = sa[q].link, sa[clone].isClone = 1;
            sa[clone].len = sa[p].len + 1, sa[cur].link = sa[q].link = clone, sa[clone].firstpos = sa[q].firstpos;
            while(p != -1 && sa[p].trans[c] == q) sa[p].trans[c] = clone, p = sa[p].link;
        }
    }
    last = cur;
}

int cnt[2 * SZ];
vector<int> odr[2 * SZ];
void numOcc() {
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i <= len; i++)
        odr[i].clear();
    for(int i = 0; i < sz; i++)
        odr[sa[i].len].push_back(i);
    for(int i = len; i > 0; i--)
        for(auto j : odr[i]) {
            cnt[j] += (sa[j].isClone == 0);
            cnt[sa[j].link] += cnt[j];
        }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> TC;
    while(TC--) {
        cin >> T, len = T.length();
        sa_init();
        for(auto c : T) sa_extend(c);
        numOcc(), ansind = 0, anslen = 0, anscnt = 0;
        for(int i = 1; i < sz; i++) {
            if(cnt[i] > 1 && sa[i].len > anslen) ansind  = sa[i].firstpos - sa[i].len + 1, anslen = sa[i].len, anscnt = cnt[i];
            else if(cnt[i] > 1 && sa[i].len == anslen) {
                int check = 0;
                for(int j = ansind, k = sa[i].firstpos - sa[i].len + 1, p = 0; p < anslen; p++, j++, k++) {
                    if (T[j] == T[k]) continue;
                    check = T[j] > T[k]; break;
                }
                if(check) ansind = sa[i].firstpos - sa[i].len + 1, anslen = sa[i].len, anscnt = cnt[i];
            }
        }
        if(anslen)  cout << T.substr(ansind, anslen) << " " << anscnt << endl;
        else cout << "No repetitions found!" << endl;
    }
    return 0;
}
