#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solveSmallBuyer(int r, int c) {
    vector<vector<ll>> costs(c, vector<int>(r, 0LL));
    vector<ll> flat(c);
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            cin >> costs[j][i];
        }
    }
    for(auto &x: flat) cin >> x;

    ll best = 1e18;
    for(int mask = 1; mask<(1 << c); mask++) {
        ll cost = 0;
        for(int i = 0; i<c; i++) if(mask & (1 << i)) cost += flat[i];
        vector<ll> mins(r, 1e17);
        for(int i = 0; i<c; i++) if(mask & (1 << i)) {
            for(int j = 0; j<r; j++) mins[j] = min(mins[j], costs[i][j]);
        }
        cost += accumulate(mins.begin(), mins.end(), 0LL);
        best = min(cost, best);
    }
    cout << best << '\n';
}

void solveOther(int r, int c) {
    vector<vector<ll>> costs(c, vector<int>(r, 0LL));
    vector<ll> flat(c);
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            cin >> costs[j][i];
        }
    }
    for(auto &x: flat) cin >> x;

    ll dp[2][c+1][1 << r];
    for(int i = c; i>=0; i--) {
    for(int mask = (1 << r) - 1; mask >= 0; mask--) {
    for(int bef = 1; bef>=0; bef--) {
        dp[bef][i][mask] = 1e18;
    }}}
    
    dp[0][c][(1 << r) - 1] = dp[1][c][(1 << r) - 1] = 0;
    for(int i = c-1; i>=0; i--) {
        for(int mask = (1 << r) - 1; mask >= 0; mask--) {
            for(int bef = 1; bef>=0; bef--) {
                dp[bef][i][mask] = dp[0][i+1][mask];
                for(int j = 0; j<r; j++) if(!(mask & (1 << j))) {
                    int cost = costs[i][j];
                    if(!bef) cost += flat[i];
                    dp[bef][i][mask] = 
                        min(dp[bef][i][mask], cost + dp[1][i][mask | (1 << j)]);
                }
            }
        }
    }
    
    cout << dp[0][0][0] << '\n';
}

void solve() {
    int r, c; cin >> r >> c;
    if(c < r) solveSmallBuyer(r, c);
    else solveOther(r, c);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
