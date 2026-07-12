#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

const ll mod = 1e9 + 7;

ll modpow(ll b, ll e) {
    ll res = 1;
    for(; e; b = (b * b) % mod, e /= 2)
        if(e & 1) res = (res * b) % mod;
    return res;
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    map<int, int> freq;
    for(int x: a) freq[x]++;
    vector<pii> na;
    ll res = 0;

    ll evens = 1;
    for(auto [a, b]: freq) {
        na.push_back({a, b});
        evens = (evens * modpow(2, b-1)) % mod;
    }
    res = (res + evens) % mod;

    sort(all(na));
    n = na.size();
    if(freq[-1]) {
        for(int i = 0; i<n-1; i++) {
            if(na[i].first == na[i+1].first - 1) {
                res = (res + evens) % mod;
            }
        }
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 0  - sum to 0 starting with +1
// -1 - sum to 1 starting with -1
