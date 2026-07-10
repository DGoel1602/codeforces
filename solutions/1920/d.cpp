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
    int n, q; cin >> n >> q;
    set<array<int, 3>> ans;
    int siz = 0;

    rep(i, 0, n) {
        int b, x; cin >> b >> x;
        if(siz > 2e18) continue;

        if(b == 1) {
            ans.insert({++siz, 1, x});
        } else {
            int osz = siz;
            siz = min((__uint128_t)3e18, (__uint128_t)siz + ((__uint128_t)siz * x));
            ans.insert({siz, 2, osz});
        }
    }

    auto dec = [&](int k, auto&& dec) -> int {
        auto it = *ans.lower_bound({k, 0, 0});
        if(it[1] == 1) return it[2];
        else {
            int left = k - it[2];
            return dec(left % it[2] == 0 ? it[2] : left % it[2], dec);
        }
    };

    rep(i, 0, q) {
        int k; cin >> k;
        cout << dec(k, dec) << " ";
    }
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
