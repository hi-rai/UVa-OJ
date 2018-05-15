#include<bits/stdc++.h>
using namespace std;

int arr[4], ans, n;
string str[] = {"banana", "quadrangle", "rectangle", "square"};

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
        if (arr[0] == arr[1] && arr[2] == arr[3] || arr[0] == arr[2] && arr[1] == arr[3] ||
            arr[0] == arr[3] && arr[2] == arr[1]) {
            if (arr[0] != arr[1] || arr[0] != arr[2]) ans = 2;
            else ans = 3;
        } else if (arr[0] >= arr[1] + arr[2] + arr[3] || arr[1] >= arr[0] + arr[2] + arr[3] ||
                   arr[2] >= arr[1] + arr[0] + arr[3] || arr[3] >= arr[1] + arr[2] + arr[0])
            ans = 0;
        else ans = 1;
        if(arr[0] == 0 || arr[1] == 0 || arr[2] == 0 || arr[3] == 0)    ans = 0;
        cout << str[ans] << endl;
    }
    return 0;
}
