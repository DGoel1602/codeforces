#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    pair<ll, ll> mima = {a[0], a[0]};
    rep(i, 1, n) {
        ll consider = a[i];
        if(consider > mima.second) mima.first = consider - mima.second;
        else if(consider < mima.first) mima.first = mima.first - consider;
        else mima.first = 0;

        mima.second += a[i];
    }
    if(mima.first * mima.first <= dist && mima.second * mima.second >= dist) return void(cout << "Yes\n");
    cout << "No\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
