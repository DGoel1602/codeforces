#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()


void solve() {
    int w, f; cin >> w >> f;
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    vi pref(n+1);
    for(int i = 1; i<=n; i++) pref[i] = pref[i-1] + a[i-1];

    ll total = accumulate(all(a), 0);

    int lo = 1, hi = 1e6;
    while(lo != hi) {
        int mid = lo + (hi - lo + 0) / 2;
        ll wp = w * mid, fp = f * mid;
        if(wp >= total || fp >= total) {
            hi = mid;
            continue;
        }

        if(fp < wp) swap(fp, wp);

        vi dp(fp+1), dp2(fp+1);
        for (int i = 0; i < fp + 1; i++) if(total - i <= wp) dp[i] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = fp; j >= 0; j--) {
                int used = pref[i - 1 + 1];
                int wpu = used - j;
                int wpl = wp - wpu;
                if (wpl < 0) continue;
                dp2[j] = dp[j] || (j + a[i] <= fp && dp[j + a[i]]);
            }
            swap(dp, dp2);
        }
        //cout << fp << "\n";
        // cout << lo << " " << hi << " " << mid << " " << dp[0][0] << " " << wp << " " << fp << endl;
        // for(int i = 0; i<n+1; i++) {
        //     for(int j = 0; j<fp+1; j++) cout << dp[i][j] << " ";
        //     cout << endl;
        // }

        if (dp[0]) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
