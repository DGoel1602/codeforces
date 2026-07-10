#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    ll n, l, r, k; cin >> n >> l >> r >> k;
    if(n % 2 == 1) return void(cout << l << "\n");
    if(n == 2) return void(cout << "-1\n");

    ll n2p = (1LL << (63 - __builtin_clzll(l))) * 2LL;
    if(n2p > r || n2p < l) return void(cout << "-1\n");

    if(k < n - 1) return void(cout << l << "\n");
    cout << n2p << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
