#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(2*n);
    for(auto &x: a) cin >> x;

    sort(a.begin(), a.end());
    ll res = 0;
    for(int i = 0; i<n; i++) res -= a[i];
    for(int i = n; i<2*n; i++) res += a[i];
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) solve();
}
