//Use DP table and edge relaxation as in Bellman Ford's algorithm

#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef tuple<int,int,int> iii;
map<string,int> ind;

vector<iii> EdgeList;
int N, M, t, TC, tc=1, Q, memo[105][105];
string str, x, y;

void calc() {
    for (int k = 1; k < N-1; k++) {
        for (int i = 0; i < N; i++)
            memo[k][i] = memo[k - 1][i];
        for (auto el:EdgeList) {
            int s, d, c;
            tie(s, d, c) = el;
            memo[k][d] = min(memo[k][d], memo[k - 1][s] + c);
        }
    }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC--) {
        cin >> N;
        ind.clear(), EdgeList.clear();
        for (int i = 0; i < N; i++) {
            cin >> str;
            ind[str] = i;
        }
        for (int i = 0; i < N; i++)
            memo[0][i] = INF;
        memo[0][0] = 0;
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> x >> y >> t;
            EdgeList.push_back(make_tuple(ind[x], ind[y], t));
            if (!ind[x]) memo[0][ind[y]] = min(t,memo[0][ind[y]]);
        }
        calc();
        cin >> Q;
        if (tc != 1) cout << "\n";
        cout << "Scenario #" << tc++ << endl;
        for (int i = 0; i < Q; i++) {
            cin >> t;
            if (t >= N-1) t = N - 2;
            if (memo[t][N - 1] >= INF) cout << "No satisfactory flights\n";
            else cout << "Total cost of flight(s) is $" << memo[t][N - 1] << "\n";
        }
    }
    return 0;
}
