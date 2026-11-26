#include <bits/stdc++.h>
using namespace std;

#define double long double

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, t; cin >> n >> m >> t;
    vector<vector<vector<double>>> dp(4, vector<vector<double>>(t+1, vector<double>(n)));
    for(int i = 0; i<4; i++) dp[i][0][0] = 1;
    vector<vector<int>> vals(4, vector<int>(6));
    for(auto &vec: vals) for(auto &x: vec) cin >> x;

    vector<vector<int>> adj(n);
    for(int i = 0; i<n; i++) adj[i].push_back(i);
    vector<int> out(n);
    for(int i = 0; i<m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        out[u] = 1;
        adj[v].push_back(u);
    }
    
    for(int k = 0; k<4; k++) {
        for(int turn = 1; turn<=t; turn++) {
            for(int pos = 0; pos<n; pos++) if(!out[pos]) {
                for(int p: adj[pos]) {
                    for(int move: vals[k]) if(p-move >= 0) {
                        dp[k][turn][pos] += 1.0/6 * dp[k][turn-1][p-move];
                    }
                }
            }
            for(int pos = 0; pos<n; pos++)
                for(int move: vals[k]) if(pos + move >= n) dp[k][turn][n-1] += 1.0/6 * dp[k][turn-1][pos];
        }
    }

    double best = 0;
    for(int me = 0; me<4; me++) {
        double win = 0;
        for(int turn = 1; turn<t; turn++) {
            double twin = dp[me][turn][n-1] - dp[me][turn-1][n-1];
            for(int ot = 0; ot<4; ot++) if(ot != me) twin *= (1 - dp[ot][turn][n-1]);
            win += twin;
        }
        vector<double> until(4);
        for(int end = 0; end<n; end++) {
            double twin = dp[me][t][end];
            if(end == n - 1) twin -= dp[me][t-1][n-1];
            for(int ot = 0; ot<4; ot++) if(ot != me) twin *= until[ot];
            for(int ot = 0; ot<4; ot++) until[ot] += dp[ot][t][end];
            win += twin;
        }
        best = max(best, win);
    }
    cout << fixed << setprecision(10) << best << '\n';

    // for(int me = 0; me<4; me++) {
    //     for(int turn = 1; turn<=t; turn++) {
    //         for(int i = 0; i<n; i++) cout << dp[me][turn][i] << " ";
    //     }
    //     cout << endl;
    // }
}
