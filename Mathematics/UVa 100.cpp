//Easy question. Just don't take the limit as given in the question as 10000 and code it for numbers upto 1000000. 
//Use long long instead of int. And check for array index overflow

#include<bits/stdc++.h>
using namespace std;

long long arr[1000005], x, y;

long long calc(long long x) {
    if (x < 1000000 && arr[x] != -1) return arr[x];
    if (x & 1) {
        if(x < 1000000) return arr[x] = 1 + calc(3 * x + 1);
        return 1 + calc(3 * x + 1);
    }
    if(x < 1000000) return arr[x] = 1 + calc(x / 2);
    return 1 + calc(x / 2);
}

long long findmax(long long x, long long y) {
    if(x > y)   return -1;
    if(x == y)  return arr[x];
    return max(findmax(x,(x+y)/2), findmax((x+y)/2 + 1, y));
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(arr, -1, sizeof arr);
    arr[1] = 1;
    for (long long i = 1; i < 1000000; i++)
        if (arr[i] == -1) calc(i);
    while (cin >> x >> y)
        cout << x << " " << y << " " << findmax(min(x, y), max(x, y)) << endl;
    return 0;
}
