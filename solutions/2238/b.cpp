#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    int res = 0;
    for(int b = 1; b <= n; b++) {
        int cnt = n / b;
        res += cnt * cnt;
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
