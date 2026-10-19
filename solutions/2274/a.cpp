#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    reverse(a.begin(), a.end());
    int res = 0;
    for(int i = 0; i<n; i++) {
        res += 2*a[i] * (i % 2 ? -1 : 1);
    }
    if(n % 2) cout << res/2 << '\n';
    else cout << -res/2 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // x = 2p - x
    // x = 2p2 - (2p - x)
    // x = 2p3 - (2p2 - (2p - x))
    // x = 2p3 - (2p2 - (2p))
    // 

    // x = 3 - (0 - 3) = 6
    // x = 2*3-0

    int t;
    cin >> t;
    while(t-- ) solve();
}
