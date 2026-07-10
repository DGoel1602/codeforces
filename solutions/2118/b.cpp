#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    cout << 2*n << '\n';
    for(int i = 1; i <= n; i++) {
        cout << i << ' ' << 1 << ' ' << n-i+1 << '\n';
        cout << i << ' ' << min(n, n-i+2) << ' ' << n << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
