#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    ll res = 0, cur = 0;
    int lb = (n-d), rb = d;
    for(int i = lb; i < n; i++) cur += a[i];
    for(int i = 1; i <= rb; i++) cur += a[i];
    res += max(0LL, 2*d*a[0] - cur);

    for(int i = 1; i < n; i++) {
        cur += a[i-1] - a[i];
        cur -= a[lb];
        lb = (lb+1) % n;
        rb = (rb+1) % n;
        cur += a[rb];
        res += max(0LL, 2*d*a[i] - cur);
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
