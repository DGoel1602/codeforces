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
    vi a(n);
    for(int &x: a) cin >> x;
    vector<pii> hoops(n);
    for(auto &[a, b]: hoops) cin >> a >> b;
    int sm = 2e9;
    for(int i = n-1; i>=0; i--) {
        sm = min(sm, hoops[i].second);
        hoops[i].second = sm;
    }

    vi deltas(n, 0);
    int c = 0;
    rep(i, 0, n) {
        if(a[i] == 1) c++;
        deltas[i] = hoops[i].second - c;
    }
    vi sufdeltas(n+1, 2e9);
    for(int i = n-1; i>=0; i--)
        sufdeltas[i] = min(deltas[i], sufdeltas[i+1]);

    vi res(a);
    int cur = 0, ch = 0;
    rep(i, 0, n) {
        auto [l, r] = hoops[i];
        int x = a[i];
        if(x != -1) {
            cur += x;
            if(cur < l || cur > r) return void(cout << "-1\n");
            continue;
        }
        if(r > cur && ch < sufdeltas[i+1]) {
            cur++;
            res[i] = 1;
            ch++;
        } else res[i] = 0;
        if(cur < l || cur > r) return void(cout << "-1\n");
    }
    for(int x: res) cout << x << " ";
    cout << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
