#include <bits/stdc++.h>
using namespace std;

#define double long double

using ll = long long;
using vi = vector<ll>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353;

ll modpow(ll b, ll e) {
    ll res = 1;
    for(; e; b = (b * b) % mod, e /= 2)
        if(e & 1) res = (res * b) % mod;
    return res;
}

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for(ll &x: a) cin >> x;
    for(ll &x: b) cin >> x;
    vector<double> divs;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(j == i) continue;
            divs.push_back((double)b[i]/b[j]);
        }
    }
    sort(all(divs));
    ll ans = 0;
    ll al = n * (n-1), inval = modpow(al, mod-2);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<i; j++) {
            double req = (double)a[i]/a[j];
            ll num = al - (upper_bound(all(divs), req) - divs.begin());
            ans = (ans + (num * inval) % mod) % mod;
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
