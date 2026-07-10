#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<int> ind(k+1, -1);
    ind[0] = 0;
    int prev = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > prev) {
            for(int j = prev+1; j <= a[i]; j++) ind[j] = i;
            prev = a[i];
        }
    }

    n = ind.size();

    vector<vector<int>> dp(n, vector(k+1, 0LL));
    int be = 0;
    for(int i = 0; i<n; i++) {
        if(ind[i] == -1) continue;
        for(int left = k; left>=i; left--) {
            if(left < i) continue;
            for(int j = 0; j<i; j++) {
                if(ind[i] == -1 || ind[j] == -1 || left - i < j) continue;
                dp[i][left] = max(dp[i][left], 
                                dp[j][left - i] + j * (ind[i] - ind[j])
                            );
            }
            be = max(be, dp[i][left] + i * (int)(a.size() - ind[i]));
        }
    }
    cout << be << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
