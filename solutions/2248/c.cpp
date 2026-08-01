#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    vi idx(n+1, -1);
    vector<pii> segs;
    for(int i =0 ; i<2*n; i++) {
        int x; cin >> x;
        if(idx[x] == -1) idx[x] = i;
        else segs.push_back({idx[x], i});
    }
    sort(all(segs));

    vi starts(n);
    rep(i, 0, n) starts[i] = segs[i].first;

    vector<int> dp(n, -1);
    auto go = [&](int i, auto&& go) -> int {
        if(i == n) return 0;
        auto &ref = dp[i];
        if(ref != -1) return ref;
        ref = go(i+1, go);
        int poss = (segs[i].second - segs[i].first + 1) * (segs[i].second - segs[i].first + 1) - (segs[i].second - segs[i].first + 1);
        ref = max(ref, poss + go(lower_bound(all(starts), segs[i].second) - starts.begin(), go));
        return ref;
    };
    cout << go(0, go) + 2 * n << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
