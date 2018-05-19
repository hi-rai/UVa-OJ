//A difficult problem
//Firstly, take the input properly, don't assume that their won't be any extra space or something like this. Test for every possible
//case otherwise it may give WA.
//Secondly, format the output properly. Whether you have to output fraction or an integer, whether the number is negative
//Thirdly, code the solution properly to check every corner case
//Check with the test cases on uDebug

#include<bits/stdc++.h>
using namespace std;

struct frac {
    long long n, d;
}_mat_[55][55];

long long gcd(long long x, long long y) {
    return y == 0 ? x : gcd(y, x % y);
}

int N_un, N_eq, TC, rnk, ans, neg;
long long t, nn, dd;
char c;
string s;

void _swap_(int r, int c) {
    if(r == c)  return;
    for (int i = 0; i <= N_un; i++)
        swap(_mat_[r][i].n, _mat_[c][i].n), swap(_mat_[r][i].d, _mat_[c][i].d);
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> TC, TC) {
        cin >> N_un >> N_eq, getline(cin, s);
        for (int i = 0; i < N_eq; i++) {
            getline(cin, s);
            stringstream in;
            in << s;
            for (int j = 0; j <= N_un; j++) {
                t = 0, neg = 0;
                while (in.get(c), c != '/' && c != ' ' && in) {
                    if (c == '-') neg = 1;
                    else t *= 10, t += (int) (c - '0');
                }
                _mat_[i][j].n = t, _mat_[i][j].d = 1, t = 0;
                if (neg) _mat_[i][j].n *= -1, neg = 0;
                if (c == '/') {
                    while (in.get(c), c != ' ' && in) {
                        if (c == '-') neg = 1;
                        t *= 10, t += (int) (c - '0');
                    }
                    _mat_[i][j].d = (neg ? -t : t);
                    t = gcd(max(abs(_mat_[i][j].n), abs(_mat_[i][j].d)), min(abs(_mat_[i][j].n), abs(_mat_[i][j].d)));
                    _mat_[i][j].d /= t, _mat_[i][j].n /= t;
                }
            }
        }
        rnk = 0, ans = 1;
        for (int i = 0, k, z = min(N_un + 1, N_eq), q = 0; i < z && q <= N_un; i++) {
            k = i;
            while (k < N_eq && _mat_[k][q].n == 0) k++;
            if (k == N_eq) {
                i--, q++;
                continue;
            } else {
                if(q == N_un)   ans = 0;
                rnk++;
            }
            _swap_(i, k);
            for (int p = i + 1; p <= N_un; p++) {
                _mat_[i][p].d *= _mat_[i][q].n, _mat_[i][p].n *= _mat_[i][q].d;
                t = gcd(max(abs(_mat_[i][p].n), abs(_mat_[i][p].d)), min(abs(_mat_[i][p].n), abs(_mat_[i][p].d)));
                _mat_[i][p].d /= t, _mat_[i][p].n /= t;
            }
            _mat_[i][q].n = _mat_[i][q].d = 1;
            for (int j = (i == 0 ? 1 : 0); j < N_eq; j + 1 == i ? j += 2 : j++) {
                for (int p = i + 1; p <= N_un; p++) {
                    nn = _mat_[i][p].n * _mat_[j][q].n, dd = _mat_[i][p].d * _mat_[j][q].d;
                    _mat_[j][p].n = _mat_[j][p].n * dd - _mat_[j][p].d * nn, _mat_[j][p].d *= dd;
                    t = gcd(max(abs(_mat_[j][p].n), abs(_mat_[j][p].d)), min(abs(_mat_[j][p].n), abs(_mat_[j][p].d)));
                    _mat_[j][p].d /= t, _mat_[j][p].n /= t;
                }
                _mat_[j][q].n = 0, _mat_[j][q].d = 1;
            }
            q++;
        }
        if (TC != 1) cout << "\n";
        cout << "Solution for Matrix System # " << TC << "\n";
        if (!ans) cout << "No Solution.\n";
        else if (rnk != N_un)
            cout << "Infinitely many solutions containing " << N_un - rnk << " arbitrary constants.\n";
        else {
            for (int i = 0; i < N_un; i++) {
                cout << "x[" << (i + 1) << "] = ";
                if (_mat_[i][N_un].d < 0 && _mat_[i][N_un].n > 0 || _mat_[i][N_un].n < 0 && _mat_[i][N_un].d > 0) cout << "-";
                cout << abs(_mat_[i][N_un].n);
                if (abs(_mat_[i][N_un].d) != 1) cout << "/" << abs(_mat_[i][N_un].d) << "\n";
                else cout << "\n";
            }
        }
    }
    return 0;
}
