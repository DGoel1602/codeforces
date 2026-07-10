#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i< b; ++i)

void solve() {
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    for(int &x: a) cin >> x;
    int kr = a[0];

    for(int &x: b) cin >> x;
    sort(all(a));
    vi bestirank;
    for(int x: b) {
        if(x <= kr) bestirank.push_back(1);
        else {
            bestirank.push_back(1 + n - (lower_bound(all(a), x) - a.begin()));
        }
    }
    sort(all(bestirank));
    for(int k = 1; k<=m; k++) {
        int res = 0;
        for(int i = k-1; i<m; i += k) res += bestirank[i];
        cout << res << " ";
    }
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
