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
    string s; cin >> s;
    int n = s.size();

    vvi dp(n, vi(n, -2));
    auto go = [&](int l, int r, auto&& go) -> int {
        if(l == r) return 0;
        if(r - l == 1) {
            if(s[r] != s[l]) return 1;
            else return 0;
        }

        auto &ref = dp[l][r];
        if(ref != -2) return ref;
        bool win = false;
        if((s[l] < s[l+1] && go(l+2, r, go) > -1 || go(l+2, r, go) == 1)
        && (s[l] < s[r] && go(l+1, r-1, go) > -1 || go(l+1, r-1, go) == 1)) win = true;

        if((s[r] < s[r-1] && go(l, r-2, go) > -1 || go(l, r-2, go) == 1)
        && (s[r] < s[l] && go(l+1, r-1, go) > -1 || go(l+1, r-1, go) == 1)) win = true;

        if(win) return ref = 1;

        bool draw = false;
        if(go(l+2, r, go) > -1 && go(l+1, r-1, go) > -1) draw = true;
        if(go(l, r-2, go) > -1 && go(l+1, r-1, go) > -1) draw = true;

        if(draw) return ref = 0;
        return ref = -1;
    };

    // for(int i = 0; i<n; i++) {
    //     for(int len = 1; len<n; len += 2) {
    //         if(i + len >= n) continue;
    //         cout << i << " " << i + len  << " " << go(i, i + len, go) << " " << s.substr(i, len + 1) << endl;
    //     }
    // }

    int res = go(0, n-1, go);
    if(res == 1) cout << "Alice\n";
    else if(res == 0) cout << "Draw\n";
    else cout << "Bob\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
