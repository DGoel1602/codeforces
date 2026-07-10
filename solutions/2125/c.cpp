#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    ll l, r; cin >> l >> r;
    l--;
    vector<ll> primes = {2, 3, 5, 7};
    ll res = r, res2 = l;
    for(int mask = 1; mask < (1 << 4); mask++) {
        ll mul = 1;
        for(int i = 0; i<4; i++) if((mask >> i) & 1) mul *= primes[i];
        ll ex = (__builtin_popcount(mask) % 2 == 0) ? 1 : -1;
        res = (res + ex * (r / mul));
        res2 = (res2 + ex * (l / mul));
    }
    cout << res - res2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
