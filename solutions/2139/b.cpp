#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll res = 0, c = max(1, s-n+1);
    for(int i = max(0, n-s); i < n; i++, c++) {
        res += a[i] * c;
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
