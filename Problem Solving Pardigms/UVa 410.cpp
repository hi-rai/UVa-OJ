#include<bits/stdc++.h>
using namespace std;

int spec[10], C, S, t=1;
double avg, imbal;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> C >> S) {
        avg = imbal = 0;
        for (int i = 0; i < S; i++)
            cin >> spec[i], avg += spec[i];
        for (int i = S; i < 2 * C; i++)
            spec[i] = 0;
        sort(spec, spec + 2 * C);
        avg /= C;
        cout << "Set #" << t++ << endl;
        for (int i = 0; i < C; i++) {
            cout << " " << i << ":";
            if (spec[i]) cout << " " << spec[i];
            if (spec[2 * C - i - 1]) cout << " " << spec[2 * C - i - 1];
            imbal += abs(avg - spec[i] - spec[2 * C - i - 1]);
            cout << endl;
        }
        cout << "IMBALANCE = " << fixed << setprecision(5) << imbal << endl << endl;
    }
    return 0;
}
