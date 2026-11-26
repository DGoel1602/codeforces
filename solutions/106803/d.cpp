#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m, 0));
    for(auto &vec: g) for(auto &x: vec) cin >> x;

    vector<vector<int>> pref(n, vector<int>(m+1, 0));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) pref[i][j+1] = pref[i][j] + g[i][j];
    }

    int best = 0;
    for(int i = 0; i<m; i++) {
        for(int j = i; j<m; j++) {
            vector<int> res;
            for(int k = 0; k<n; k++) res.push_back(pref[k][j+1] - pref[k][i]);
            int mx = 0, cur = 0;
            for(int k = 0; k<res.size(); k++) {
                cur += res[k];
                cur = max(0LL, cur);
                mx = max(mx, cur);
            }
            best = max(best, mx);
        }
    }

    cout << best << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
