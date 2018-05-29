#include<bits/stdc++.h>
#define SZ 20010
using namespace std;

struct state {
    int len, link, isClone, firstpos;
    map<char, int> trans;
};

state sa[2 * SZ];
int last, sz, len;

void sa_init() {
    last = 0, sz = 1;
    sa[0].link = -1, sa[0].len = 0;
    sa[0].isClone = 0, sa[0].firstpos = -1;
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

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC, t, p;
    string T;
    cin >> TC;
    while(TC--) {
        cin >> T;
        sa_init(), t = 0, p = 0, len = T.length();
        for(auto c : T) sa_extend(c);
        for(auto c : T) sa_extend(c);
        while(p < len)    t = (*(sa[t].trans.begin())).second, p++;
        cout << sa[t].firstpos - len + 2 << endl;
    }
    return 0;
}
