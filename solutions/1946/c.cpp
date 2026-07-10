#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

void solve() {
    int n, k; cin >> n >> k;
    vvi adj(n);
    rep(i,0,n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi subsz(n);
    auto dfs1 = [&](int u, int p, auto&& dfs1) -> int {
        subsz[u] = 1;
        for(int v: adj[u]) if(v != p) subsz[u] += dfs1(v, u, dfs1);
        return subsz[u];
    };
    dfs1(0,-1,dfs1);

    auto dfs = [&](int u, int p, int si, auto&& dfs) -> pair<int, int> {
        int res = 0;
        int mz = 1;
        for(int v: adj[u]) if(v != p){
            if(subsz[v] >= si) {
                pii ch = dfs(v, u, si, dfs);
                res += ch.first;
                mz += ch.second;
            }
            else mz += subsz[v];
        } 
        if(mz >= si) res++;
        return {res, mz < si ? mz : 0}; 
    };

    // auto centroid = [&](int u, int p, auto&& centroid) -> int {
    //     for(int v: adj[u]) if(v != p && subsz[v] > (n/2)) return centroid(v, u, centroid);
    //     return u;
    // };

    int root = 0;
    dfs1(root,-1,dfs1);

    int lo = 1, hi = n;
    while(lo != hi) {
        int m = lo + (hi - lo + 1) / 2;
        // cout << "TRYING: " <<  m << " " << root << " " << dfs(root,-1,m,dfs).first << endl;
        if(dfs(root,-1,m,dfs).first <= k) hi = m - 1;
        else lo = m;
    }

    cout << lo << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
