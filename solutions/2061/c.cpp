#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    map<tuple<int, int, bool>, ll> dp;

    auto go = [&](int l, int i, bool force_true, auto&& go) -> ll {
        if(dp.count({l, i, force_true})) return dp[{l, i, force_true}];
        if(i == n) return 1LL;
        if(force_true) {
            if(l == a[i]) return go(l, i+1, false, go);
            else return 0LL;
        }

        return dp[{l, i, force_true}] = 
                    (go(l+1, i+1, true, go) + (l == a[i] ? go(l, i+1, false, go) : 0))
                    % 998244353;  
    };

    cout << go(0, 0, false, go) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
