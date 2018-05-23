//A good problem that illustrates the use of diophantine equation
//First find whether two lift are accessible from one-other. This can be checked by using diophantine equations and checking for
//feasible solution
//Then use UFDS to make set of all lifts accessible from floor A, and similarly from floor B. 
//Now check if the two floors are accessible from lifts of same set

#include<bits/stdc++.h>
using namespace std;

int p[305], r[305], x, y, gcd, Y[305], X[305], F, E, A, B, TC, check, a, b, q, s, t, swapped;
bool accA[305], accB[305];
double l1, l2, h1, h2;

void init() {
    for (int i = 0; i < 305; i++)
        p[i] = i, r[i] = 0, accA[i] = accB[i] = false;
}

int findSet(int x) {
    return x == p[x] ? x : p[x] = findSet(p[x]);
}

void unionSet(int x, int y) {
    int a = findSet(x), b = findSet(y);
    if (r[a] > r[b]) p[b] = a, accA[a] |= accA[b], accB[a] |= accB[b];
    else p[a] = b, accA[b] |= accA[a], accB[b] |= accB[a];
    if (r[a] == r[b]) r[b]++;
}

void extendedEuclid(int a, int b) {
    if (b == 0) { x = 1, y = 0, gcd = a; return; }
    extendedEuclid(b, a % b);
    swap(x, y);
    y = y - a / b * x;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        init(), check = 0;
        cin >> F >> E >> A >> B;
        for (int i = 0; i < E; i++) {
            cin >> X[i] >> Y[i];
            double ch = (A - Y[i]) / (double) X[i];
            if (abs(ch - floor(ch)) < 1e-9 && ch >= 0) accA[i] = true;
            ch = (B - Y[i]) / (double) X[i];
            if (abs(ch - floor(ch)) < 1e-9 && ch >= 0) accB[i] = true;
        }
        for (int i = 0; i < E; i++)
            for (int j = i + 1; j < E; j++) {
                if (X[i] == 0) {
                    double d2 = (Y[i] - Y[j]) / X[j];
                    if (d2 >= 0 && abs(d2 - floor(d2)) < 1e-9) unionSet(i, j);
                } else if (X[j] == 0) {
                    double d1 = (Y[j] - Y[i]) / X[i];
                    if (d1 >= 0 && abs(d1 - floor(d1)) < 1e-9) unionSet(i, j);
                } else {
                    if (X[i] < X[j]) swap(i, j), swapped = 1;
                    else swapped = 0;
                    extendedEuclid(X[i], X[j]);
                    if((Y[i]- Y[j]) % gcd)  {
                        if(swapped)   swap(i,j);
                        continue;
                    }
                    q = (Y[j] - Y[i]) / gcd, s = x * q, t = y * (q);
                    a = (F - Y[i]) / X[i], b = (F - Y[j]) / X[j];
                    l1 = -s * gcd / (double) X[j], h1 = (a - s) * gcd / (double) X[j];
                    h2 = (b + t) * gcd / (double) X[i], l2 = t * gcd / (double) X[i];
                    if (l2 <= l1 && h1 <= h2) {
                        if (ceil(l1) <= floor(h1)) unionSet(i, j);
                    } else if(l1 <= l2 && h2 <= h1) {
                        if (ceil(l2) <= floor(h2)) unionSet(i, j);
                    }else if (l1 <= l2 && h1 >= l2) {
                        if (ceil(l2) <= floor(h1)) unionSet(i, j);
                    } else if (l1 <= h2 && h1 >= h2) {
                        if (ceil(l1) <= floor(h2)) unionSet(i, j);
                    }
                    if (swapped) swap(i, j), check = 0;
                }
            }
        for (int i = 0; i < 300 && !check; i++)
            if (accA[findSet(i)] && accB[findSet(i)]) check = 1;
        if (check) cout << "It is possible to move the furniture.\n";
        else cout << "The furniture cannot be moved.\n";
    }
    return 0;
}
