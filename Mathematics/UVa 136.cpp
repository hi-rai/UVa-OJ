#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<long long> arr;
    arr.insert(1);
    long long t[] = {2, 3, 5};
    for (auto it = arr.begin(); it != arr.end(); it++)
        if ((*it) <= (long long) 1e10)
            for (int j = 0; j < 3; j++)
                arr.insert((*it) * t[j]);
    auto it = arr.begin();
    for(int i = 1; i < 1500; i++, it++);
    cout << "The 1500'th ugly number is " << (*it) << ".\n";
    return 0;
}
