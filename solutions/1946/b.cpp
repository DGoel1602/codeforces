#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;

    ll ma = 0, cur = 0;
    for(ll x: a) {
        cur = max(0LL, cur + x);
        ma = max(cur, ma);
    }
    ma = max(cur, ma);

    const ll mod = 1e9 + 7;
    ma = ma % mod;
    cur = ma;

    rep(i, 0, k) {
        cur = (cur * 2) % mod;
    }

    ll res = 0;
    for(ll x: a) res = (res + mod + x) % mod;
    cout << (((res + mod - ma) % mod) + cur) % mod << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
