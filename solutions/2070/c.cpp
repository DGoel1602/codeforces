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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vi a(n);
    vector<int> cs = {0};
    rep(i, 0, n) {
        int x; cin >> x;
        a[i] = x;
        cs.push_back(x);
    }
    sort(all(cs));

    int lo = 0, hi = n;
    while(lo < hi) {
        int m = (lo + hi) / 2;

        int blocks = 0;
        rep(i, 0, n) {
            if(a[i] <= cs[m]) continue;
            if(s[i] == 'B') blocks = 1;
            break;
        }

        bool sr = false;
        rep(i, 0, n) {
            if(a[i] <= cs[m]) continue;
            if(s[i] == 'R') sr = true;
            if(s[i] == 'B') {
                if(sr) blocks++;
                sr = false;
            }
        }
        if(blocks <= k) hi = m;
        else lo = m + 1;
    }

    cout << (cs[lo]) << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// >=4
// 10 2
// B R B R B B R R B R
// 5 1 2 4 5 3 6 1 5 4
