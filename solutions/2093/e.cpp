#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<ll, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    for(int &x: a) cin >> x;

    auto works = [&](int mex) -> bool {
        int parts = 0;
        set<int> seen;
        for(int i = 0; i<n; i++) {
            if(a[i] < mex) seen.insert(a[i]);
            if(seen.size() == mex) {
                seen.clear();
                parts++;
            }
        }
        return parts >= k;
    };

    int lo = 0, hi = n+1;
    while(lo != hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if(!works(mid)) hi = mid - 1;
        else lo = mid;
    }

    cout << lo << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
