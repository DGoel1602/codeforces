#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll


using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m, d; cin >> n >> m >> d;
    m++;
    vi p(m), r(m);
    p[0] = 0, r[0] = 0;
    rep(i, 1, m) cin >> p[i] >> r[i];
    for(int i = 1; i<m; i++) r[i] = r[i-1] + r[i];
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<m; j++) {
            int li = p[i], lj = p[j];
            int mo = (li + lj + 1) % n;
            int div = (li + lj + 1) / n;
            int nx = upper_bound(all(p), mo) - p.begin() - 1;
            int res = div * r.back() + d * (li + lj + 1) + r[nx];
            if(r[i] + r[j] + d * (p[i] + p[j]) > res) return void(cout << "YES\n");
        }
    }
    cout << "NO\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
