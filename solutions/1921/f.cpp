#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    map<pair<int, int>, vector<array<int, 3>>> qs;
    for(int i = 0; i<q; i++) {
        int s, d, k; cin >> s >> d >> k;
        --s;
        qs[{s%d, d}].push_back({s, k, i});
    }
    vector<int> res(q);
    for(auto [p, vec]: qs) {
        auto [sd, d] = p;
        int cnt = 0;
        vector<int> progpref = {0}, sumpref = {0};
        for(int i = sd; i<n; i+=d) {
            progpref.push_back(progpref.back() + (++cnt) * a[i]);
            sumpref.push_back(sumpref.back() + a[i]);
        }
        for(auto [s, k, i]: vec) {
            int idx = (s-sd)/d;
            int idx2 = idx+k;
            res[i] = (progpref[idx2] - progpref[idx]) - (idx * (sumpref[idx2] - sumpref[idx]));
        }
    }
    for(int x: res) cout << x << " ";
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
