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
    ll n, k; cin >> n >> k;
    vi res(n);
    int l = 0, r = n - 1;

    if(n < 60 && (1LL << (n-1)) < k) return void(cout << "-1\n");

    for(int i = 1; i<=n-1; i++) {
        if(n - i < 60) {
            ll all = 1LL << (n - i);
            if (all / 2 >= k) res[l] = i, l++;
            else res[r] = i, r--, k -= all / 2;
        } else {
            res[l] = i, l++;
        }
    }
    if(res[l] == 0) res[l] = n;
    else res[r] = n;

    for(int x: res) cout << x << " ";
    cout << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
