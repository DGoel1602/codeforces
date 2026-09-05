#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int dp[101][101][101];

void solve() {
    int n; cin >> n;

    auto go = [&](int left, int pile, int x, auto&& go) -> int {
        if(left < 0) return 0;
        if(pile == 0) return x != 0 && left == 0;

        auto &ref = dp[left][pile][x];
        if(ref != -1) return ref;

        if(left == 0) return ref = x != 0;

        ref = 0;
        for(int stones = 1; stones<=left; stones++) {
            ref = (ref + go(left - stones, pile - 1, x ^ stones, go)) % mod;
        }

        return ref;
    };

    cout << go(n, n, 0, go) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    memset(dp, -1, sizeof(dp));

    int t; cin >> t;
    while(t--) solve();
}
