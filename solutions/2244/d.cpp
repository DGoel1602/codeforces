#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, m; cin >> n >> m;
    vi flips(n);
    vi a(n);
    for(int &x: a) cin >> x;
    rep(i, 0, m) {
        int x; cin >> x;
        --x;
        flips[x] = true;
    }
    
    int mi = 0, ma = 0;
    for(int i = 0; i<n; i++) {
        int omi = mi, oma = ma;
        if(!flips[i]) {
            ma = max({oma + a[i], omi + a[i]});
            mi = min({oma + a[i], omi + a[i]});
        } else {
            ma = max({oma + a[i], omi + a[i], -oma - a[i], -omi - a[i]});
            mi = min({oma + a[i], omi + a[i], -oma - a[i], -omi - a[i]});
        }
    }
    cout << ma << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
