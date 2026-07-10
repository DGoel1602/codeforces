#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vi a(n); 
    for(int &x: a) cin >> x;
    
    vector<vvi> dp(n, vvi(2, vi(2, -1e18)));
    vector<vvi> flip(n, vvi(2, vi(2, 0)));
    
    auto go = [&](int i, int par, int any, auto&& go) -> int {
        if(i == -1) return 0;
        auto& ref = dp[i][par][any];
        if(ref != (int)-1e18) return ref;
        
        ref = go(i-1, par, any, go) + (par ? -a[i] : a[i]);
        
        if(a[i] > 0 || any) {
            int tr = go(i-1, par^1, 1, go) + (par ? a[i] : -a[i]);
            if(tr > ref) {
                ref = tr;
                flip[i][par][any] = 1;
            }
        }
        
        return ref;
    };
    
    go(n-1, 0, 0, go);
    
    vi res;
    int cur = n-1, p = 0, an = 0;
    while(cur != -1) {
        if(flip[cur][p][an]) {
            res.push_back(cur);
            p ^= 1;
            an = 1;
        }
        cur--;
    }
    set<int> can, wait;
    for (int idx : res) {
        if (a[idx] > 0) can.insert(idx);
        else wait.insert(idx);
    }

    vi order;
    while (!can.empty() || !wait.empty()) {
        if (can.empty()) break;
        int idx = *can.begin();
        order.push_back(idx);
        can.erase(can.begin());
        auto it = wait.begin();
        while (it != wait.end() && *it<=idx) {
            can.insert(*it);
            it = wait.erase(it);
        }
    }

    cout << res.size() << "\n";
    for(int x: order) cout << x + 1 << " ";
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
