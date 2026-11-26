#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int b, k, x; cin >> b >> k >> x;

    vector<int> coins;
    int cur = 1;
    coins.push_back(cur);
    for(int l = 1; l<=k; l++) {
        cur *= b;
        if(cur > x) break;
        coins.push_back(cur);
    }

    // cout << x << " " << coins.back() << endl;
    int res = 0;
    for(int i = (int)(coins.size()) - 1; i>=0; i--) {
        res += x / coins[i];
        x %= coins[i];
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;
    while(T--) solve();
}
