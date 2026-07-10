#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

int dp[201][201][201];

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    auto go = [&](int aa, int bb, int cc, auto&& go) -> int {
        if(aa < 0 || bb < 0 || cc < 0) return 0;
        if(aa == 0 && bb == 0 && cc == 0) return 0;
        if(dp[aa][bb][cc] != -1) return dp[aa][bb][cc];

        int res = 0;
        if(aa % 2 == 0 && bb % 2 == 0 && cc % 2 == 0) res++;
        if(aa % 2 == 1 && bb % 2 == 1 && cc % 2 == 1) res++;
        return dp[aa][bb][cc] = res + max({go(aa-1, bb, cc, go), go(aa, bb-1, cc, go), go(aa, bb, cc-1, go)});
    };
    cout << go(a, b, c, go) + (d / 2) << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    int t; cin >> t;
    while(t--) solve();
}
