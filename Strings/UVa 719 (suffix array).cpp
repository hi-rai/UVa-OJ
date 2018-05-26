//The solution to finding smallest cyclic shift using suffix array

#include<bits/stdc++.h>
#define SZ 100010
using namespace std;

int SA[SZ], tempSA[SZ], RA[SZ], tempRA[SZ], c[SZ], LCP[SZ], len;
char T[SZ];

void cntSort(int k) {
    int maxi = max(len, 300);
    memset(c, 0, sizeof c);
    for(int i = 0; i < len; i++)
        c[i + k < len ? RA[i + k] : 0]++;
    for(int i = 0, sum = 0; i < maxi; i++)
        c[i] += sum, swap(c[i], sum);
    for(int i = 0; i < len; i++)
        tempSA[c[SA[i] + k < len ? RA[SA[i] + k] : 0]++] = SA[i];
    for(int i = 0; i < len; i++)
        SA[i] = tempSA[i];
}

void constructSA() {
    len = strlen(T);
    for(int i = 0; i < len; i++)
        SA[i] = i, RA[i] = T[i];
    for(int i = 1; i < len; i <<= 1) {
        cntSort(i);
        cntSort(0);
        tempRA[SA[0]] = 0;
        for(int j = 1, r = 0; j < len; j++) {
            if(RA[SA[j]] == RA[SA[j - 1]] && (SA[j] + i < len ? RA[SA[j] + i] : 0) == (SA[j - 1] + i < len ? RA[SA[j - 1] + i] : 0))
                tempRA[SA[j]] = r;
            else tempRA[SA[j]] = (++r);
        }
        for(int j = 0; j < len; j++)
            RA[j] = tempRA[j];
        if(RA[len - 1] == len - 1)  break;
    }
}

void calcLCP() {
    int phi[SZ], PLCP[SZ];
    phi[SA[0]] = -1;
    for(int i = 1; i < len; i++)
        phi[SA[i]] = SA[i - 1];
    for(int i = 0, L = 0; i < len; i++) {
        if(phi[i] == -1) { phi[i] = 0; continue; }
        while(T[i + L] == T[phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(0, L - 1);
    }
    for(int i = 0; i < len; i++)
        LCP[i] = PLCP[SA[i]];
}

int smallestCyclicShift() {
    int l = strlen(T), ind;
    for(int i = 0; i < l; i++)  T[l + i] = T[i];
    T[2 * l] = '$', T[2 * l + 1] = '\0';
    constructSA(), calcLCP();
    for (ind = 0; ind < len; ind++)
        if (len - SA[ind] - 1 >= l && LCP[ind + 1] < l)
            return SA[ind];
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> T;
        cout << smallestCyclicShift() + 1 << endl;
    }
    return 0;
}
