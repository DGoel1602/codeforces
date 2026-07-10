#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if(a == b && b == 0) return void(cout << "0\n");
    int g = __gcd(a, b);
    a /= g; b /= g;
    int mi = max(a, b);
    if(mi <= c) return void(cout << "1\n");
    cout << "2\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
