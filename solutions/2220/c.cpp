#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

void solve() {
    int p, q; cin >> p >> q;
    for(int n = 1; n * n <= 3e8; n++) {
        int m = (2*q+p-n)/(1+2*n);
        if(2*q+p != 2*n*m + n + m) continue;
        if(q > (n*m)+min(n, m)) continue;
        if(m < 1) continue;
        return void(cout << n << " " << m << '\n');
    }
    cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 2 * n + 2 * m + (n - 1) * m + (m - 1) * n
// n(m + 1) + m(n + 1)
// q <= m * n + 1
// 2 * q + p == 2*n*m + n + m
// (2*q + p - n) = m(1+2*n)
// (2*q + p - n)/(1+2*n) = m
// 3e8
// 10 2
// 20/(5) = 4

//  - - - -
// | | | | |
//  - - - -
// | | | | |
//  - - - -
