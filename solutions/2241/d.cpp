#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    int cur = 0;
    for(int i = 0; i<n; i++) {
        cur += b[i] - a[i];
        if(cur < 0) return void(cout << "NO\n");
    }
    cout << "YES\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
