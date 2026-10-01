#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> pts(n);
    for(auto &[a, b]: pts) cin >> a >> b;
    for(auto &[a, b]: pts) a *= k, b *= k;
    int mny = 1e18, mnx = 1e18, mxy = 0, mxx = 0;
    for(auto &[a, b]: pts) {
        mxx = max(mxx, a);
        mxy = max(mxy, b);
        mnx = min(mnx, a);
        mny = min(mny, b);
    }
    if(abs(mxx - mnx) > m || abs(mxy - mny) > m) {
        cout << "-1\n";
        return 0;
    }
    for(auto &[a, b]: pts) cout << (a - mnx) << " " << b - mny << '\n';
}
