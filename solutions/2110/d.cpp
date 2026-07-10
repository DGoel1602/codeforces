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
    int n, m; cin >> n >> m;
    vi bs(n);
    for(int &x: bs) cin >> x;
    vector<vector<pii>> adj(n);
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }

    int lo = 0, hi = 1e15;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        vi dp(n, -1);
        dp[0] = bs[0];
        rep(i, 0, n) {
            for(auto [v, w]: adj[i]) {
                if(w > mid || dp[i] < w) continue;
                dp[v] = max(dp[v], dp[i] + bs[v]);
            }
        }
        if(dp[n-1] == -1) lo = mid + 1;
        else hi = mid;
    }
    cout << (lo > 1e9 ? -1 : lo) << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
