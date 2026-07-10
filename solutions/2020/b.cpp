#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

ll nums(int n) {
    ll lo = 0, hi = 1e9 + 100;
    while(lo != hi) {
        ll m = lo + (hi - lo + 1) / 2;
        if(m * m < n) lo = m;
        else hi = m - 1;
    }
    return lo;
}

void solve() {
    ll n; cin >> n;
    ll lo = 1, hi = 3e18;
    while(lo != hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if(mid - nums(mid) > n) hi = mid - 1;
        else lo = mid;
    }
    cout << lo << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
