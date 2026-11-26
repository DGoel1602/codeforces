#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    sort(a.begin(), a.end());
    ll best = 0;
    for(int i = 0; i<n; i++) {
        best = max(best, (n-i)*a[i]);
    }
    cout << best << '\n';
}
