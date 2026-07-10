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
    int n; cin >> n;
    vector<vector<ll>> nums(n+1);
    for(int i = 0; i<n; i++) {
        ll a, b; cin >> a >> b;
        nums[a].push_back(b);
    }
    ll res = 0;
    for(int i = 1; i<=n; i++) {
        sort(all(nums[i]), greater<>());
        for(int j = 0; j<min(i, (int)nums[i].size()); j++) res += nums[i][j];
    }
    cout << res << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
