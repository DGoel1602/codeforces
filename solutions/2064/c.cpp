#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> ppref(n), npref(n);
    for(int i = 0; i<n; i++) ppref[i] = (i == 0 ? 0 : ppref[i-1]) + max(0LL, a[i]);
    for(int i = n-1; i>=0; i--) npref[i] = (i == n - 1 ? 0 : npref[i+1]) + abs(min(0LL, a[i]));
    int res = 0;
    for(int i = 0; i<n; i++) res = max(res, ppref[i] + npref[i]);
    cout << res << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
