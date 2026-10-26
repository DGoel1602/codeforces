#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define sz(x) (int)((x).size())
#define all(x) begin(x), end(x)
using vi = vector<int>;

void solve() {
    int n, p;
    cin >> n >> p;
    p--;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll k; int t;
    cin >> k >> t;

    auto tri = [&](int t1, int t2) -> ll {
        ll x = (ll)(t1)*(ll)(t1+1)/2, y = (ll)(t2)*(ll)(t2+1)/2;
        return y-x;
    };

    vector<ll> pf(n+1);
    for(int i = 1; i <= n; i++) pf[i] = a[i-1] + pf[i-1];

    ll res = 0;
    for(int i = p; i < min(p+t, n); i++) {
        int t1 = i-p, t2 = t-t1;
        int rs = min(i+1, t2);
        ll sum = pf[i+1] - pf[i+1-rs] + k*tri(t-rs, t);
        res = max(res, sum);
    }

    reverse(a.begin(), a.end());
    p = n-1-p;
    pf = vector<ll>(n+1);
    for(int i = 1; i <= n; i++) pf[i] = a[i-1] + pf[i-1];

    for(int i = p; i < min(p+t, n); i++) {
        int t1 = i-p, t2 = t-t1;
        int rs = min(i+1, t2);
        ll sum = pf[i+1] - pf[i+1-rs] + k*tri(t-rs, t);
        res = max(res, sum);
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
