#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n; cin >> n;
    vector<ll> res;
    for(int i = 63; i>=0; i--) {
        if((n >> i) & 1LL && __builtin_popcount(n) != 1) res.push_back(n & ~(1LL << i));
    }
    res.push_back(n);
    cout << res.size() << "\n";
    for(ll x: res) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
