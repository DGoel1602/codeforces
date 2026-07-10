#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n, m, p, q; cin >> n >> m >> p >> q;
    if((n % p == 0 && (m % q != 0 || n / p != m / q))) cout << "NO\n";
    else cout << "YES\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 5 2 3 4
// -1 -1 6 -1 -1
