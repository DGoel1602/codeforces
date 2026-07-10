#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        ll cur = a[n-2];
        for(int i = n-3; i >= 0; i--) cur -= a[i];
        cout << a[n-1] - cur << '\n';
    }
}
