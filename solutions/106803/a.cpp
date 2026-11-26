#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<int> dp(n, 1e18);
    dp[0] = 0;
    for(int i = 0; i<n; i++) {
        for(int j = max(i-3, 0LL); j<i; j++) dp[i] = min(dp[i], dp[j] + (a[i] - a[j]) * (a[i]- a[j]));
    }
    cout << dp[n-1]<< '\n';
}
