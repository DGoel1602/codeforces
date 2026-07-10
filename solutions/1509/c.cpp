#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    map<int, int> freq;
    rep(i, 0, n) {
        int x; cin >> x;
        freq[x]++;
    }
    vector<pii> a = {{0, 0}};
    for(auto [el, f]: freq) a.push_back({el, f});
    a.push_back({1e18, 0});

    n = a.size();
    vvi dp(n, vi(n, -1));
    auto dfs = [&](int l, int r, auto &&dfs) -> int {
        if(l < 0 && r == n - 1) return 0;
        if(l == 0 && r >= n) return 0;
        if(l < 0 || r >= n) return 1e18;

        if(dp[l][r] != -1) return dp[l][r];
        int mi = a[l+1].first, ma = a[r-1].first;
        return dp[l][r] = min(
                (ma - a[l].first) * a[l].second + dfs(l-1, r, dfs), 
                (a[r].first - mi) * a[r].second + dfs(l, r+1, dfs)
            );
    };

    int b = 1e18;
    for(int i = 1; i<n-1; i++)
        b = min(b, dfs(i - 1, i + 1, dfs));

    cout << b << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
