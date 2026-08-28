#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;

    auto works = [&](int m) -> bool {
        string sn = to_string(m);
        vector<vector<vector<int>>> dp(sn.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        auto go = [&](int i, int tight, int zero, auto && go) -> int {
            if(i == sn.size()) return !zero;
            auto &ref = dp[i][tight][zero];
            if(ref != -1) return ref;
            int res = 0;
            for(int d = 0; d<10; d++) if(d != k || (zero && d == 0)) {
                if(tight && d > sn[i] - '0') break;
                res += go(i+1, tight && d == sn[i] - '0', zero && d == 0, go);
            }
            return ref = res;
        };
        return go(0, 1, 1, go) >= n;
    };
    ll lo = 1, hi = 1e13;
    while(lo != hi) {
        int m = lo + (hi - lo) / 2;
        if(!works(m)) lo = m + 1;
        else hi = m;
    }
    cout << lo << '\n';
}
