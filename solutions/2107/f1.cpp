#include <bits/stdc++.h>
using namespace std;


using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    vector<int> dp(n, -1);
    auto go = [&](int i, auto&& go) -> int {
        if(i == -1) return 0;
        auto &ref = dp[i];
        if(ref != -1) return ref;
        ref = 1e18;
        int idx = i;
        for(int j = i; j>=0; j--) {
            if(a[idx] > a[j]) idx = j;
            int cost = (i - idx) + a[idx] + (i - j) * (a[idx] + 1);
            ref = min(ref, cost + go(j-1, go));
        }
        return ref;
    };
    cout << go(n-1, go) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
