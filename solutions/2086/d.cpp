#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

const ll mod = 998244353;

ll modpow(ll b, ll e) {
    ll res = 1;
    for(; e; b = (b * b) % mod, e /= 2) if(e & 1) res = (res * b) % mod;
    return res;
}

void solve() {
    vi freqs(26);
    for(int &x: freqs) cin >> x;
    vi left(26);
    left[25] = freqs[25];
    for(int i = 24; i>=0; i--)
        left[i] = freqs[i] + left[i+1];

    int s = left[0] + 5;
    vi facs(s, 1), invfacs(s, 1);
    for(int i = 1; i<sz(facs); i++) facs[i] = (facs[i-1] * i) % mod, invfacs[i] = modpow(facs[i], mod - 2);

    int reqodds = (left[0] / 2) + (left[0] % 2), reqevens = (left[0] / 2);

    auto choose = [&](int x, int k) -> int {
        if(x < k) return 0;
        return (facs[x] * ((invfacs[k] * invfacs[x-k]) % mod)) % mod;
    };

    vvi dp(27, vi(reqodds+1, 0));
    for(int i = 0; i<=reqodds; i++) dp[26][i] = 1;
    for(int i = 25; i>=0; i--) {
        for(int j = 0; j<reqodds + 1; j++) {
            int evens = left[i] - j;
            if (evens < 0) continue;
            if (freqs[i] == 0) {
                dp[i][j] = dp[i + 1][j];
                continue;
            }
            dp[i][j] = (dp[i + 1][j] * choose(evens, freqs[i])) % mod;
            if(j - freqs[i] >= 0) dp[i][j] = (dp[i][j] + (dp[i + 1][j - freqs[i]] * choose(j, freqs[i])) % mod) % mod;
        }
    }
    cout << dp[0][reqodds] << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}


//101010
