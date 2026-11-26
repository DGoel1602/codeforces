#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, E; cin >> N >> E;
    vector<array<int, 4>> costs(N);
    for(auto &[a, b, c, d]: costs) cin >> a >> b >> c >> d;

    vector<vector<int>> dp(N, vector<int>(E + 1, -1));
    auto go = [&](int i, int lf, auto&& go) -> int {
        if(lf < 0) return 1e18;
        if(i == N) return 0;
        auto &ref = dp[i][lf];
        if(ref != -1) return ref;

        return ref = min(
            costs[i][1] + go(i+1, lf-costs[i][0], go),
            costs[i][3] + go(i+1, lf-costs[i][2], go)
        );
    };

    int res = go(0, E, go);
    if(res > 1e10) cout << "-1\n";
    else cout << res << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
