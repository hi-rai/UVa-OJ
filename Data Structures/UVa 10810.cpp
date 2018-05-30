#include<bits/stdc++.h>
using namespace std;

int a[500005], b[500005], n;
long long cnt;

void merge(int l, int r, int L, int R) {
    int i = l, j = L, k = 0;
    while (i <= r && j <= R) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++], cnt += (r - i + 1);
    }
    while (i <= r) b[k++] = a[i++];
    while (j <= R) b[k++] = a[j++];
    for (int p = l, q = 0; p <= R; p++, q++)
        a[p] = b[q];
}

void mergeSort(int l, int r) {
    if (r <= l) return;
    int t = (l + r) / 2;
    mergeSort(l, t);
    mergeSort(t + 1, r);
    merge(l, t, t + 1, r);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while(cin >> n, n) {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        cnt = 0;
        mergeSort(0, n - 1);
        cout << cnt << endl;
    }
    return 0;
}
