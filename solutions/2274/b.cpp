#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    int mn = 0, mx = 0;
    int res = -1e18;
    for(int i =0 ; i<n; i++) {
        vector<pair<int, int>> ops = {{mn, a[i] - mn}, {mn, a[i] + mn}, {mx, a[i] - mx}, {mx, a[i] + mx}};
        int nmn = 1e18, nmx = -1e18;
        for(auto [o, x]: ops) {
            res = max(res, x);
            nmn = min(nmn, o + x);
            nmx = max(nmx, o + x);
        }
        mn = nmn, mx = nmx;
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    // x = 2p - x
    // x = 2p2 - (2p - x)
    // x = 2p3 - (2p2 - (2p - x))
    // x = 2p3 - (2p2 - (2p))
    // 

    // x = 3 - (0 - 3) = 6
    // x = 2*3-0

    int t;
    cin >> t;
    while(t-- ) solve();
}
