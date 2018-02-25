#include<bits/stdc++.h>
using namespace std;

map<string, int> ans;
string country, name;

int tot;
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> tot;
    while (tot--) {
        cin >> country;
        getline(cin, name);
        if (ans.find(country) == ans.end())
            ans[country] = 1;
        else
            ans[country]++;
    }
    for (auto i:ans)
        cout << i.first << " " << i.second << endl;
    return 0;
}
