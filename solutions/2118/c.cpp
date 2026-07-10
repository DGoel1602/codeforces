#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    for(int i = 0; i<63; i++) {
        int cost = 1LL << i;
        if(cost > k) break;
        for(int j = 0; j<n; j++) if(!(a[j] & (1LL << i))) {
            if(cost > k) break;
            a[j] |= (1LL << i);
            k -= cost;
        }
    }
    int res = 0;
    for(int i = 0; i<n; i++) res += __builtin_popcountll(a[i]);
    cout << res << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
