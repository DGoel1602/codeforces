#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    vi idcs(n + 1);
    rep(i, 0, n) idcs[a[i]] = i;
    
    for(int i = 1; i<=n; i++) {
        int idx = idcs[i];
        
        int c = 0, e = 0;
        rep(j, 0, idx) {
            if(a[j] > i) c++;
            if(a[j] > 2 * n - i) e++;
        }
        rep(j, idx+1, n) {
            if(a[j] < i) c++;
            if(a[j] < 2 * n - i) e++;
        }
        
        if(c > e) a[idx] = 2 * n - i;
    }

    // for(int x: a) cout << x << " ";
    // cout << "\n";

    int t = 0;
    rep(i, 0, n)
        rep(j, i+1, n)
            if(a[j] < a[i]) t++;
    cout << t << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
