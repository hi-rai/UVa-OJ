//An easy problem. Don't need specific algorithms and can be solved just by counting the number of times a ray from the point 
//towards positive x-direction crosses a line vertical line segment of the polygon

#include<bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int> > v;
int n, x, y, lx, ly;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n, n) {
        v.clear();
        cin >> lx >> ly;
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            if (y != ly)    v.push_back(make_tuple(x, min(y, ly), max(y, ly)));
            lx = x, ly = y;
        }
        sort(v.begin(), v.end());
        cin >> x >> y;
        int ind = 0, tot = v.size(), cnt = 0;
        while (get<0>(v[ind]) < x) ind++;
        while (ind < tot) {
            if (y < get<2>(v[ind]) && y > get<1>(v[ind])) cnt++;
            ind++;
        }
        if (cnt & 1) cout << "T" << endl;
        else cout << "F" << endl;
    }
    return 0;
}
