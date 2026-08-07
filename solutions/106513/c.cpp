#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    vector<vector<int>> dp(1 << n, vector<int>(n+1, -1));
    vector<vector<int>> costs(n+1, vector<int>(n, 0));
    for(int &x: costs[n]) cin >> x;
    rep(i, 0, n) for(int &x: costs[i]) cin >> x;

    rep(i, 0, n) dp[(1 << n) - 1][i] = 0;
    auto go = [&](int cur, int ls, auto&& go) {
        auto &ref = dp[cur][ls];
        if(ref != -1) return ref;
        ref = 1e9;
        for(int i = 0; i<n; i++) if(!(cur & (1 << i)))
            ref = min(ref, costs[ls][i] + go(cur | (1 << i), i, go));
        return ref;
    };
    cout << go(0, n, go) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while(t--) solve();
}
