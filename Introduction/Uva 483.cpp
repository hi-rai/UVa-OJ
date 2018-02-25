#include<bits/stdc++.h>
using namespace std;

string str, temp;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (getline(cin, str), cin) {
        stringstream in;
        in << str;
        bool check = false;
        while (in >> temp) {
            reverse(temp.begin(), temp.end());
            if (check) cout << " ";
            else check = true;
            cout << temp;
        }
        cout << endl;
    }
    return 0;
}
