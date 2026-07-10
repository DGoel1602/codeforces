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
    int n, c; cin >> n >> c;
    ll res = (c + 1) * (c + 2) / 2;
    vi a(n);
    for(int &x: a) cin >> x;
    int os = 0, es = 0;
    for(int i = n-1; i>=0; i--) {
        int x = a[i];
        res -= (x/2) + 1;
        res -= c - x;
        res += (x % 2 == 1 ? os : es);

        //cout << x << " " << res << "\n";
        if(x % 2 == 1) os++; 
        else es++;
    }
    cout << res << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}


// 0 0
// 0 1
// //0 2
// //0 3
// 1 1
// //1 2
// 1 3
// 2 2
// 2 3
// 3 3
