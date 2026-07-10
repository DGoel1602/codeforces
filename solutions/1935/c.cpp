#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    ll n, l; cin >> n >> l;
    vector<array<int, 2>> cs(n);
    for(auto &[b, a]: cs) cin >> a >> b;
    sort(all(cs));
    reverse(all(cs));

    vi a(n), b(n);
    rep(i, 0, n) a[i] = cs[i][1], b[i] = cs[i][0];

    vvi dp(n+1, vi(n+1, 2e18));
    rep(i, 1, n+1) dp[i][0] = min(dp[i-1][0], a[i-1] + b[i-1]);

    if(*min_element(all(a)) > l) return void(cout << "0\n");

    int be = 1;
    rep(k, 1, n) {
        rep(i, 1 + k, n+1) {
            dp[i][k] = min(dp[i-1][k], dp[i-1][k-1] + a[i-1]);
            if(dp[i-1][k-1] + a[i-1] - b[i-1] <= l) be = k + 1;
        }
    }
    cout << be << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
