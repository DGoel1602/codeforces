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
    vector<array<int, 3>> ps(n);
    rep(i, 0, n) {
        int a, b; cin >> a >> b;
        ps[i] = {a,b,i};
    }
    sort(all(ps), [&](array<int, 3> a, array<int, 3> b) -> bool {
        if(a[0] < b[0]) return true;
        if(a[0] > b[0]) return false;

        if(a[1] > b[1]) return true;
        return false;
    });

    int end = -1;
    vi res;
    rep(i, 0, n) {
        if(ps[i][1] > end) res.push_back(ps[i][2]), end = ps[i][1];
    }
    cout << res.size() << "\n";
    for(int x: res) cout << x + 1 << " ";
    cout << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
