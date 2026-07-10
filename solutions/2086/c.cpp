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
    vi p(n), d(n);
    for(int &x: p) cin >> x, x--;
    for(int &x: d) cin >> x, x--;

    vi vis(n, 0);
    int zs = 0;
    rep(i, 0, n) {
        int cur = d[i];
        while(vis[cur] == 0) {
            vis[cur] = 1;
            cur = p[cur];
            zs++;
        }
        cout << zs << " ";
    }
    cout << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
