//bit tricky coding else the problem is easy. Take care that a number (2, 3, 5, 7) can also be a factor many times

#include<bits/stdc++.h>
using namespace std;

vector<int> humble;
bitset<2000000009> taken = 3;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    humble.push_back(1);
    int tot = 1, arr[] = {2, 3, 5, 7}, ind = 0, n;
    while (true) {
        for (auto i: arr) {
            long long temp = i * (long long) humble[ind];
            while (temp <= 2000000000LL) {
                if (!taken[temp]) tot++, taken[temp] = true, humble.push_back(temp);
                temp *= i;
            }
        }
        ind++;
        if (tot >= 5842) break;
    }
    sort(humble.begin(), humble.end());
    while (cin >> n, n) {
        cout << "The " << n;
        if (n % 10 == 1 && ((n % 100) / 10) != 1) cout << "st";
        else if (n % 10 == 2 && ((n % 100) / 10) != 1) cout << "nd";
        else if (n % 10 == 3 && ((n % 100) / 10) != 1) cout << "rd";
        else cout << "th";
        cout << " humble number is " << humble[n - 1] << ".\n";
    }
    return 0;
}
