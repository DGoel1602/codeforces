#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 998244353;
ll modpow(ll b, ll e) {
    ll res = 1;
    for(; e; b = (b*b)%mod, e >>= 1) {
        if(e & 1) res = (res*b) % mod;
    }
    return res;
}

void solve() {
    ll n, m, r, c;
    cin >> n >> m >> r >> c;
    ll res = modpow(2, r*c-1);
    res = (res * modpow(modpow(2, c-1), n-r)) % mod;
    res = (res * modpow(modpow(2, r-1), m-c)) % mod;
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
