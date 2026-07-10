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
    vi a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    vi mima(2, 0);
    for(int i = 0; i<n; i++) {
        int o1 = mima[0] - a[i], o2 = mima[1] - a[i];
        int o3 = b[i] - mima[0], o4 = b[i] - mima[1];
        mima[0] = min({o1, o2, o3, o4});
        mima[1] = max({o1, o2, o3, o4});
    }
    cout << mima[1] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
