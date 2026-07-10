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

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    rep(i, 0, n)
        if(a[i] > b[i]) swap(a[i], b[i]);
    
    ll cm = *max_element(all(a));
    ll cur = accumulate(all(b), 0LL) + cm;

    ll be = 0;
    rep(i, 0, n) {
        ll test = cur + a[i] - b[i];
        if(b[i] > cm) test += b[i] - cm;
        be = max(be, test);
    }

    cout << be << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
