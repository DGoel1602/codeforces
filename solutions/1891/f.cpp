#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    int lo, hi, mid;
    int val = 0;
    Node *left, *right;
    Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
        if(l == r - 1) return;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }

    void update(int i, int x) {
        if(lo == hi - 1) return void(val += x);
        if(i < mid) left->update(i, x);
        else right->update(i, x);
        val = left->val + right->val;
    }
    
    int query(int l, int r) {
        if(l >= hi || r <= lo) return 0;
        if(r >= hi && l <= lo) return val;
        return left->query(l, r) + right->query(l, r);
    }
};

void solve() {
    int q; cin >> q;
    vector<vector<pair<int, int>>> ops = {{}};
    vector<int> w = {-1};
    vector<vector<int>> adj(1);
    for(int i = 0; i<q; i++) {
        int t; cin >> t;
        if(t == 1) {
            int p; cin >> p;
            --p;
            adj[p].push_back(adj.size());
            w.push_back(i);
            ops.push_back({});
            adj.push_back({});
        } else {
            int v, x; cin >> v >> x;
            --v;
            ops[v].push_back({i, x});
        }
    }
    Node st(0, q+5);
    vector<int> vals(ops.size());
    auto dfs = [&](int u, auto&& dfs) -> void {
        for(auto [idx, x]: ops[u]) st.update(idx, x);
        vals[u] = st.query(w[u], q+5);
        for(int v: adj[u]) dfs(v, dfs);
        for(auto [idx, x]: ops[u]) st.update(idx, -x);
    };
    dfs(0, dfs);
    for(int x: vals) cout << x << " ";
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
