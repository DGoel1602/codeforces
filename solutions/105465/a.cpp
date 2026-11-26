#include <bits/stdc++.h>
using namespace std;
#include <assert.h>

using ll = long long;
#define sz(a) (int)(a).size()
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(int i = (a); i < (b); i++)

#define int ll

void solve() {
    int n;
    cin >> n;

    ll base = (1LL << 40) - 1;
    
    vector<ll> vals(40, (1LL << 40)-1);
    vector<char> seen(40);
    for (int i = 0; i < n; i++) {
        ll v; cin >> v;
        base &= v;
        for (int j = 0; j < 40; j++) {
            if (v & (1LL << j)) {
                seen[j]=1;
                vals[j] &= v;
            }
        }
    }

    vector<ll> guys;
    for (int i = 0; i < 40; i++) if (seen[i]) guys.push_back(vals[i]);

    sort(all(guys));
    n = sz(guys);
    vector<ll> guys2;
    for (int i = 0; i < n; i++) {
        ll o = base;
        for (int j = 0; j < i; j++) {
            if ((guys[j] | guys[i]) == guys[i]) o |= guys[j];
        }
        if (o != guys[i]) guys2.push_back(guys[i]);
    }
    n = sz(guys2);
    int p1 = min(n, 20LL), p2 = n-p1;
    vector<ll> dp((1LL << p2));
    vector<ll> bad(n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if ((guys2[i] | guys2[j]) == guys2[j]) bad[i] |= (1LL << j);
        }
    }
    for (ll m = 0; m < (1LL << p2); m++) {
        bool f = 1;
        for (int i = 0; i < p2; i++) {
            if (!(m & (1LL << i))) continue;
            if (m & (bad[i+p1] >> p1)) f = 0;
        }
        if (f) dp[m]++;
    }

    for (int i = 0; i < p2; i++) {
        for (int m = 0; m < (1LL << p2); m++) {
            if (m & (1LL<<i)) dp[m] += dp[m^(1LL<<i)];
        }
    }

    ll ans = 0;

    for (ll m = 0; m < (1LL << p1); m++) {
        bool f = 1;
        ll scary = 0;
        for (int i = 0; i < p1; i++) {
            if (!(m & (1LL << i))) continue;
            if (m & bad[i]) f = 0;
            scary |= (bad[i] >> p1);
        }
        // cout << scary << endl;
        // cout << ((1LL << p1) - 1) - scary << endl;
        if (f) ans += dp[((1LL << p2) - 1) - scary];
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T=1;
    // cin >> T;
    while (T--) {
        solve();
    }
}
