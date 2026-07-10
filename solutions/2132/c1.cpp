#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
    vector<pii> cs = {{1, 3}};
    for(int i = 1; i<20; i++) {
        cs.push_back({pow(3,i), pow(3,i+1) + i * pow(3,i-1)});
    }
    int n; cin >> n;
    ll res = 0;
    for(int i = cs.size()-1; i>=0; i--) {
        while(cs[i].first <= n) {
            n -= cs[i].first;
            res += cs[i].second;
        }
    }
    cout << res << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
