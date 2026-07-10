#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    x = min(x, y);
    cout << 0 << " " << x << " " << x << " " << 0 << "\n";
    cout << 0 << " " << 0 << " " << x << " " << x << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
