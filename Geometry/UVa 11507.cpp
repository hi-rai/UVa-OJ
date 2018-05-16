//An easy problem. Can be solved by encoding an array for each of 24 possible moves

#include<bits/stdc++.h>
using namespace std;

int arr[][4] = {{5,4,0,0}, {4,5,1,1}, {2,2,5,4}, {3,3,4,5}, {0,1,2,3}, {1,0,3,2}}, L, t;
map<string,int> ind;
string s;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ind["+y"] = 0, ind["-y"] = 1, ind["+z"] = 2, ind["-z"] = 3, ind["+x"] = 4, ind["-x"] = 5;
    while(cin>>L, L) {
        L--, t = 4;
        while (L--) {
            cin >> s;
            if (s != "No") t = arr[t][ind[s]];
        }
        if (t == 0) cout << "+y" << endl;
        else if (t == 0) cout << "+y" << endl;
        else if (t == 1) cout << "-y" << endl;
        else if (t == 2) cout << "+z" << endl;
        else if (t == 3) cout << "-z" << endl;
        else if (t == 4) cout << "+x" << endl;
        else cout << "-x" << endl;
    }
    return 0;
}
