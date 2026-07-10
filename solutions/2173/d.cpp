#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
    int n, k; cin >> n >> k;

    vector<vvi> dp(35, vvi(35, vi(2, -1)));

    auto go = [&](int i, int j, int c, auto&& go) -> int {
        if(i == 31) return 0;

        auto &ref = dp[i][j][c];
        if(ref != -1) return ref;

        int cur = (n >> i) & 1;
        if(cur && c) return ref = 1 + go(i + 1, j, 1, go);
        if(!cur && c) {
            if(!j) return ref = go(i+1, j, 0, go);
            return ref = max(go(i+1, j, 0, go), 1 + go(i+1, j-1, 1, go));
        } 
        if(cur && !c) {
            if(!j) return ref = go(i+1, j, 0, go);
            return ref = max(go(i+1, j, 0, go), 1 + go(i+1, j-1, 1, go));
        }
        return ref = go(i+1, j, 0, go);
    };

    int be = 0;
    for(int i = 0; i<=min(32, k); i++) {
        be = max(be, go(0, i, 0, go) + k - i);
    }
    cout << be << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
