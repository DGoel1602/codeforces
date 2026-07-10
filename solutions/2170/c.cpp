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
    ll n, k; cin >> n >> k;
    vector<ll> qss(n), rs(n);
    for(ll &x: qss) cin >> x;
    for(ll &x: rs) cin >> x;
    sort(all(rs));
    multiset<ll> qs;
    for(ll x: qss) qs.insert(x);

    int res = 0;
    for(ll r: rs) {
        r = r + 1;
        auto hi = qs.upper_bound((k - r + 1)/r);
        if(hi == qs.begin()) continue;
        hi--;
        qs.erase(hi);
        res++;
    }
    cout << res << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
