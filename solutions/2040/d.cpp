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
    int n; cin >> n;
    vvi adj(n);
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi res(n);
    auto dfs = [&](int u, int p, int a, auto&& dfs) -> int {
        if(a > 2 * n) return -1;

        res[u] = a;
        int cur = 1, ret = a;
        for(int v: adj[u]) if(v != p) {
            int num = a + cur;
            
            if(cur == 1) cur += 3;
            else cur += 2;

            int mx = dfs(v, u, num, dfs);
            if(mx == -1) return -1;

            //cout << u + 1 << " " << v + 1 << " " << mx << endl;

            ret = max(ret, mx);

            cur = max(a+cur, mx+1) - a;
            if(cur % 2 == 1) cur++;
        }
        return ret;
    };
    int mx = dfs(0, -1, 1, dfs);
    if(mx == -1) return void(cout << "-1\n");

    for(int x: res) cout << x << " ";
    cout << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
