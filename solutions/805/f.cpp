#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

#define int ll

using pii = pair<int, int>;
pii merge(pii a, pii b) {
    pii n;
    n.first = a.first + b.first;
    n.second = a.second + b.second;
    return n;
}

struct Node {
    int lo, hi, mid;
    pair<int, int> val = {0, 0};
    Node *left = nullptr, *right = nullptr;
    Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
    }
    void check() {
        if(lo == hi - 1) return;
        if(left == nullptr) left = new Node(lo, mid);
        if(right == nullptr) right = new Node(mid, hi);
    }

    void update(int i, int x) {
        if(lo == hi - 1) {
            val.first += lo * x;
            val.second += x;
            return;
        }
        check();
        if(i < mid) left->update(i, x);
        else right->update(i, x);
        val = merge(left->val, right->val);
    }

    pii query(int l, int r) {
        if(l >= hi || r <= lo) return {0, 0};
        if(r >= hi && l <= lo) return val;
        pii res = {0, 0};
        if(left != nullptr) res = merge(res, left->query(l, r));
        if(right != nullptr) res = merge(res, right->query(l, r));
        return res;
    }
};

struct DSU {
    int n;
    vector<int> sz, p;
    vector<int> mx;
    DSU(int n): n(n), sz(n, 1), p(n), mx(n, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if(p[x] != x) return p[x] = find(p[x]);
        return p[x];
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        if(sz[b] > sz[a]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

signed main() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    DSU dsu(n);
    for(int i = 0; i<m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dsu.join(u, v);
    }
    vector<int> seen(n, 0);
    vector<int> far(n, 0);
    for(int i = 0; i<n; i++) if(!seen[i]) {
        map<int, int> dist;
        auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
            seen[u] = 1;
            dist[u] = d;
            for(int v: adj[u]) if(v != p) dfs(v, u, d+1, dfs);
        };
        dfs(i, -1, 0, dfs);
        int a = i;
        for(auto [el, cnt]: dist) if(dist[a] < cnt) a = el;
        dist.clear();
        dfs(a, -1, 0, dfs);
        int b = i;
        for(auto [el, cnt]: dist) if(dist[b] < cnt) b = el;
        map<int, int> a_res(dist);
        dist.clear();
        dfs(b, -1, 0, dfs);
        map<int, int> b_res(dist);
        for(auto [el, cnt]: a_res) far[el] = max(far[el], cnt);
        for(auto [el, cnt]: b_res) far[el] = max(far[el], cnt);
    }
    vector<Node> sts(n, Node(0, n));
    vector<vector<int>> els(n);
    for(int i = 0; i<n; i++) {
        dsu.mx[dsu.find(i)] = max(dsu.mx[dsu.find(i)], far[i]);
        sts[dsu.find(i)].update(far[i], 1);
        els[dsu.find(i)].push_back(far[i]);
    }

    map<pair<int, int>, double> dp;
    while(q--) {
        int u, v; cin >> u >> v;
        --u; --v;
        u = dsu.find(u);
        v = dsu.find(v);
        if(u == v) {
            cout << "-1\n";
            continue;
        }
        int mx = max(dsu.mx[v], dsu.mx[u]);
        if(els[v].size() < els[u].size()) swap(u, v);
        if(dp.count({u, v})) {
            cout << setprecision(10) << fixed << dp[{u, v}] << '\n';
            continue;
        }
        double res = 0;
        for(int x: els[u]) {
            pii cnt_low = sts[v].query(0, mx - x);
            int cnt_above = sts[v].val.second - cnt_low.second;
            int t_above = sts[v].val.first - cnt_low.first;
            res += cnt_low.second * mx;
            res += t_above + (1 + x) * cnt_above;
        }
        res = res / (els[v].size() * els[u].size());
        dp[{u, v}] = res;
        cout << setprecision(10) << fixed << res << '\n';
    }
}
