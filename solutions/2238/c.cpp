#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 1; i<n; i++) {
        int x; cin >> x;
        --x; 
        adj[x].push_back(i);
    }

    vector<int> heights(n);
    auto dfs = [&](int u, int d, auto&& dfs) -> void {
        heights[u] = d;
        for(int v: adj[u]) dfs(v, d+1, dfs);
    };
    
    dfs(0, 0, dfs);

    int tot = 0;
    auto dfs2 = [&](int u, auto&& dfs2) -> map<int, int> {
        map<int, int> res;
        res[heights[u]] = 1;
        set<int> used;
        for(int v: adj[u]) {
            auto ch = dfs2(v, dfs2);
            if(ch.size() > res.size()) swap(ch, res);
            for(auto [el, cnt]: ch) {
                if(!cnt) continue;
                if(res.count(el) && !used.count(el)) tot++, used.insert(el);
                res[el] += cnt;
            }
        }
        tot++;
        return res;
    };

    dfs2(0, dfs2);
    cout << tot << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
