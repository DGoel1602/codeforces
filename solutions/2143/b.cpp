#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(k);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < k; i++) cin >> b[i];
    sort(b.begin(), b.end());

    ll cost = 0;
    int p = 0;
    for(int i = 0; p < n; i++) {
        if((i >= k) || (n-p < b[i])) {
            cost += a[p++];
            continue;
        }
        for(int j = 0; j < b[i]-1; j++) cost += a[p++];
        p++;
    }
    cout << cost << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
