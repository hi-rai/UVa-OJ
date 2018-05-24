//A bit complex to keep track of all the changes.
//Make sure when you update the erdos number of one then you update the erdos number of everyone related to it

#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef vector<int> vi;
map<string, int> ind;
vi erdos, t;
vector<vi> l, w;
string str, p;
int TC, tc = 1, id, N, P, cnt, sr;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        ind.clear(), ind["Erdos, P."] = 0, id = 1;
        erdos.clear(), erdos.push_back(0);
        l.clear(), w.clear(), w.push_back(vi(0));
        cin >> N >> P;
        cin.ignore(), sr = -1;
        while (sr++, N--) {
            getline(cin, str), t.clear();
            int x = 0;
            while (true) {
                cnt = 0, p = "";
                while (true) {
                    if (str[x] == ',') cnt++;
                    if (cnt == 2 || str[x] == ':') break;
                    p += str[x], x++;
                }
                if (ind.count(p) == 0) ind[p] = id++, erdos.push_back(INF), w.push_back(vi(0));
                t.push_back(ind[p]), w[ind[p]].push_back(sr);
                if (str[x] == ':') break;
                else x += 2;
            }
            int m = INF;
            for (auto i: t)
                m = min(m, erdos[i]);
            vi upd;
            for (auto i: t)
                if (erdos[i] > m + 1) {
                    for (auto j : w[i]) {
                        if (j == sr) continue;
                        for (auto k : l[j]) {
                            if (erdos[k] > m + 2)
                                erdos[k] = m + 2, upd.push_back(k);
                        }
                    }
                    erdos[i] = m + 1;
                }
            l.push_back(t);
            for (int i = 0; i < upd.size(); i++)
                for (auto j : w[upd[i]])
                    for (auto k : l[j]) {
                        if (erdos[k] > erdos[upd[i]] + 1)
                            erdos[k] = erdos[upd[i]] + 1, upd.push_back(k);
                    }
        }
        cout << "Scenario " << tc++ << endl;
        while (P--) {
            getline(cin, str);
            if (ind.count(str) == 0 || erdos[ind[str]] == INF) cout << str << " " << "infinity\n";
            else cout << str << " " << erdos[ind[str]] << "\n";
        }
    }
    return 0;
}
