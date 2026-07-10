#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int l, n; cin >> l >> n;
    vi res(n+1);
    ll t = 0;
    int cur = n;
    while(cur > 0) {
        int bits = __lg(cur) + 1;
        int am = (1 << bits) - 1;
        int lb = am - cur;
        rep(i,lb,cur+1) res[i] = (~i) & am, t += i | res[i];
        cur = lb-1;
    }
    cout << t << "\n";
    for(int x: res) cout << x << " ";
    cout << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 7 8 5 4 3 2 9 0 1 6

// 0111 | 0000 = 0111 = 7
// 1000 | 0001 = 1001 = 9
// 0101 | 0010 = 0111 = 7
// 0100 | 0011 = 0111
// 0011 | 0100 = 0111
// 0010 | 0101 = 0111
// 1001 | 0110 = 1111 = 15
// 0000 | 0111 = 0111
// 0001 | 1000 = 1001
// 0110 | 1001 = 1111 = 15


// 0 1 2
// 1 2 1

// 1 + 3 + 2 = 6

// 100
// 000 - 011
// 001 - 011
// 010 - 011
// 011 - 111
// 100 - 111


// 000 | 000 - 000 (0)
// 001 | 010 - 011 (2)
// 010 | 001 - 011 (1)
// 011 | 100 - 111 (4)
// 100 | 011 - 111 (3)
