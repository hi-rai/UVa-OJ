#include<bits/stdc++.h>
using namespace std;

int N, n;
string s;

long long f(long long x) {
    int len = s.length();
    long long t, u;
    vector<long long> v;
    for (int i = 0; i < len - 3; i++) {
        if (s[i] == ' ') continue;
        else if (s[i] == '+') {
            t = v.back(), v.pop_back(), u = v.back(), v.pop_back();
            v.push_back((t + u) % N);
        } else if (s[i] == '*') {
            t = v.back(), v.pop_back(), u = v.back(), v.pop_back();
            v.push_back((t * u) % N);
        } else if (s[i] == '%') {
            t = v.back(), v.pop_back(), u = v.back(), v.pop_back();
            v.push_back(u % t);
        } else if (s[i] == 'x') {
            v.push_back(x);
        } else {
            t = 0;
            while (s[i] != ' ')
                t *= 10, t += (int) (s[i++] - '0');
            v.push_back(t);
        }
    }
    return v.back() % N;
}

long long cycleFind() {
    long long tort = f(n), hare = f(f(n)), cyc_length = 1;
    while (tort != hare) tort = f(tort), hare = f(f(hare));
    hare = n;
    while (tort != hare) hare = f(hare), tort = f(tort);
    tort = f(hare);
    while (tort != hare) cyc_length++, tort = f(tort);
    return cyc_length;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> N >> n, getline(cin, s), N)
        cout << cycleFind() << endl;
    return 0;
}
