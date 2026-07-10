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
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    sort(all(a));
    ll ones = 0, total = 0, ab = 0;
    ll fit = 0;
    for(int i = 0; i<n; i++) {
        if(a[i] == 1) ones++;
        else {
            ab++;
            total += a[i];
            fit += (a[i] / 2)-1;
        }
    }
    total += min(ones, fit);
    ones -= min(ones, fit);
    if(ones && ab == 1) total++;
    cout << (total >= 3 ? total : 0) << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}


// 1 1 0 1 1 0 1 1
