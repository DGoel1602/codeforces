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
    vi a(n);
    for(int &x: a) cin >> x;
    int res = 0;
    for(int i = n-2; i>=0; i--) {
        int k = (a[i]+a[i+1]-1)/a[i+1];
        a[i] = a[i]/k;
        res += k-1;
    }
    cout << res << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
