#include <bits/stdc++.h>
using namespace std;

using ll = __int128_t;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

void solve() {
    long long _n, _b, _c; cin >> _n >> _b >> _c;
    int n = _n, b = _b, c = _c;
    if(b == 0 && c < n - 2) return void(cout << "-1\n");
    if(b == 0) return void(cout << (_n - (_c <= _n - 1)) << '\n');
    long long lo = 0, hi = n;
    auto works = [&](int m) -> bool {
        int val = m == 0 ? 0 : c + (m - (int)1) * b;
        return val <= n - 1;
    };
    
    while(lo != hi) {
        int m = lo + (hi - lo + (int)1) / (int)2;
        if(!works(m)) hi = m - (int)1;
        else lo = m;
    }
    cout << _n - lo << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    long long t; cin >> t;
    while(t--) solve();
}
