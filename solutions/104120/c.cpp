#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> pref(n+1, 0);
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i-1];

    int ep = n;
    while(m--) {
        ll x; cin >> x;
        for(; ep > 0 && a[ep-1] >= x; ep--);
        cout << pref[ep] + x*(n-ep) << '\n';
    }
}
