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
    int n; cin >> n;
    vvi adj(n);
    for(int i = 1; i<n; i++) {
        int p; cin >> p; --p;
        adj[p].push_back(i);
    }
    vi a(n);
    for(int &x: a) cin >> x;

    auto dfs = [&](int u, auto&& dfs) -> pii {
        if(!adj[u].size()) return {a[u], a[u]};
        vector<pii> res;
        int idx = -1;
        for(int v: adj[u]) {
            pii ch = dfs(v, dfs);
            if(ch.first == -1) return {-1, -1};
            res.push_back(ch);
            if(idx == -1 || res[idx].first > res.back().first) 
                idx = res.size()-1;
        }
        pii r = {res[idx].first, res[idx].second};
        for(int i = (idx+1)%res.size(); i != idx; i = (i+1)%res.size()) {
            if(r.second == res[i].first - 1) {
                r.second = res[i].second;
            } else return {-1, -1};
        }
        return r;
    };
    pii res = dfs(0, dfs);
    if(res.first == -1) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 4 3 1 2
// 3 2 1
// 2 1 3
// 1 3 2
