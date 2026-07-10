#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n, k; cin >> n >> k;
    vvi adj(n);
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(k == 1) return void(cout << n-1 << "\n");

    vvi dp(n, vi(k+1, 0));
    vector<int> ord;
    vector<int> par(n);

    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        par[u] = p;
        for(int v: adj[u]) if(v != p) dfs(v, u, dfs);
        ord.push_back(u);
    };
    dfs(0, -1, dfs);

    for(int l = 0; l<=k; l++) {
        for(int u: ord) {
            if(l == 0) dp[u][l] = 1;
            else for(int v: adj[u]) if(v != par[u]) dp[u][l] += dp[v][l-1];
        }
    }

    ll ret = dp[0][k];
    reverse(all(ord));

    for(int u: ord) {
        if(u == 0) continue;
        for(int i = k; i>=1; i--) {
            int wme = dp[par[u]][i-1] - (i - 2 >= 0 ? dp[u][i-2] : 0);
            dp[u][i] += wme;
        }
        ret += dp[u][k];
    }

    cout << ret / 2 << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}


//        1
//       /|\ 
//      2 7 3
//     /     \ 
//    9       4
//             \ 
//              5
//               \ 
//                6
//               / \ 
//              10  8

// 1 - 2
// 2 - 0
// 3 - 1
// 4 - 1
// 5 - 2
// 6 - 0
// 7 - 0
// 8 - 0
// 9 - 0
// 10 - 0
