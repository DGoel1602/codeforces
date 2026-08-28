#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k; cin >> n >> k;
    vector<array<int, 3>> a(n);
    for(auto &vec: a) for(int &x: vec) cin >> x;
    vector<int> pref(n+1);
    for(int i = 1; i<n+1; i++) pref[i] = pref[i-1] + a[i-1][2];
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    auto go = [&](int i, int ls, auto&& go) {
        if(i == n) return 0LL;
        auto &ref = dp[i][ls+1];
        if(ref != -1) return ref;
        ref = 1e18;
        int comeIn = k - (pref[i] - pref[ls+1]) % k;
        if(comeIn == k) comeIn = 0;
        if(i == ls + 1) comeIn = k;
        int req = (a[i][2] - comeIn + k - 1) / k;
        if(req > a[i][1] - a[i][0]) return ref;
        if(req == a[i][1] - a[i][0] && i < n - 1 && a[i+1][0] == a[i][1])
            return ref = go(i+1, ls, go);
        int wasting = k - (a[i][2] - comeIn + k) % k;
        if(wasting == k) wasting = 0;
        return ref = min(go(i+1, ls, go), go(i+1, i, go) + wasting);
    };
    int res = go(0, -1, go) + pref[n];
    // for(int i = 0; i<n; i++) {
    //     for(int j = -1; j<n; j++) if(dp[i][j+1] != -1) cout << i << " " << j << " " << dp[i][j+1] << endl;
    // }
    cout << (res < 1e18 ? res : -1) << '\n';
}
