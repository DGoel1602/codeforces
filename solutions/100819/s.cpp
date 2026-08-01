#include <bits/stdc++.h>
using namespace std;
#define int  long long
signed main(){

    int n; cin >> n;

    vector<array<int, 3>> a(n);
    for(auto &[a, b, c]: a) cin >> a >> b >> c;
    sort(a.begin(), a.end());

    set<pair<int, int>> vec;
    for(int i = 0; i<n; i++) vec.insert({a[i][0], i});
    vec.insert({1e7, n});

    vector<int> dp(n+1, 0);
    for(int i = n-1; i>=0; i--) {
        dp[i] = dp[i+1];
        pair<int, int> it = *vec.lower_bound({a[i][0] + a[i][2], 0});
        dp[i] = max(dp[i], a[i][1] + dp[it.second]);
    }
    cout << dp[0] << '\n';


    return 0;
}
