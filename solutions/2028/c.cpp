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
    int n, m, v; cin >> n >> m >> v;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> cnt(n+1);
    int cur = 0;
    for(int i = 0; i<n; i++) {
        cur += a[i];
        if(i > 0) cnt[i+1] = cnt[i];
        if(cur >= v) cur = 0, cnt[i+1]++;
    }
    cur = 0;
    int cur2 = 0;
    if(cnt.back() < m) return void(cout << "-1\n");
    vi pref(n+1);
    for(int i = 1; i<n+1; i++) pref[i] = pref[i-1] + a[i-1];
    int best = pref[n] - pref[lower_bound(all(cnt), m) - cnt.begin()];
    for(int i = n-1; i>=0; i--) {
        cur += a[i];
        if(cur >= v) cur = 0, cur2++;
        int left = m - cur2;
        int idx = lower_bound(all(cnt), left) - cnt.begin();
        best = max(best, pref[i] - pref[idx]);

    }
    cout << best << '\n';

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
