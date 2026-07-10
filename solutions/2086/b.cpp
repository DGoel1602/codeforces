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

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vi a(n);
    for(int &x2: a) cin >> x2;
    ll s = accumulate(all(a), 0LL);
    int div = x / s; 
    int rem = x % s;

    if(rem == 0) div--, rem = s;

    int ex = 0;
    s = 0;
    for(int i = n-1; i>=0; i--) {
        s += a[i];
        if(s >= rem) break;
        ex++;
    }
    cout << max(0LL, n * k - (div * n + ex)) << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
