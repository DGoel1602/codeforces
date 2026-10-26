#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define sz(x) (int)((x).size())
#define all(x) begin(x), end(x)
using vi = vector<int>;

struct DSU {
    vi p, s, par, cc;
    vector<array<array<int, 5>, 3>> st;

    DSU(int n, vector<int> &par, vector<vector<int>> &adj) : p(n), s(n, 1), par(par), cc(n) {
        for(int i = 0; i < n; i++) cc[i] = sz(adj[i]) - (i != 0);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int find(int u) {
        if(u == p[u]) return u;
        return find(p[u]);
    }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if(s[a] < s[b]) swap(a, b);
        int pn = a, cn = b;

        array<array<int, 5>, 3> rb;
        rb[0] = {a, s[a], p[a], cc[a], par[a]};
        rb[1] = {b, s[b], p[b], cc[b], par[b]};
        if(par[a] != -1 && find(par[a]) == b) swap(pn, cn);
        int pNode = par[pn];
        if(par[pn] == -1) rb[2] = {-1, -1, -1, -1, -1};
        else {
            pNode = find(pNode);
            rb[2] = {pNode, s[pNode], p[pNode], cc[pNode], par[pNode]};
        }
        st.push_back(rb);

        cc[a] = cc[pn] = cc[pn] - s[cn] + cc[cn];
        if(par[pn] != -1) cc[pNode] += s[cn];
        s[a] += s[b], p[b] = a;
        par[a] = pNode;
    }
    void rollback(int t) {
        for(int i = 0; i < t; i++) {
            array<array<int, 5>, 3> rb = st.back();
            st.pop_back();
            for(int j = 0; j < 3; j++) {
                auto [idx, si, pi, cci, pari] = rb[j];
                if(idx == -1) continue;
                s[idx] = si, p[idx] = pi, cc[idx] = cci, par[idx] = pari;
            }
        }
    }
};

vector<pair<int, int>> edges;
vector<pair<int, int>> ql;
struct Node {
    int lo, hi, mid;
    vector<int> val;
    Node *left, *right;

    Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
        if(l == r - 1) return;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }

    void update(int l, int r, int i) {
        if(l >= hi || r <= lo) return;
        if(r >= hi && l <= lo) return void(val.push_back(i));
        left->update(l, r, i);
        right->update(l, r, i);
    }

    void walk(DSU &dsu) {
        for(int x: val) {
            dsu.join(edges[x].first, edges[x].second);
        }
        if(lo != hi - 1) {
            left->walk(dsu);
            right->walk(dsu);
        }
        
        if(lo == hi - 1 && lo != ql.size() && ql[lo].first == 2) {
            int comp = dsu.find(ql[lo].second);
            int par = dsu.par[comp];
            int res = dsu.s[comp] + dsu.cc[comp] + (par == -1 ? 0 : dsu.s[dsu.find(par)]);
            cout << res << '\n';
        }

        dsu.rollback(val.size());
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);

    vector<int> init(n-1);
    for(int i = 0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
        edges.push_back({u, v});
        cin >> init[i];
    }

    vector<int> state(n-1), prev(n-1);
    for(int i = 0; i < n-1; i++) {
        if(init[i] == 0) state[i] = 1, prev[i] = 0;
    }

    vector<array<int, 3>> events;
    ql.resize(m);
    for(int i = 0; i < m; i++) {
        int t, x;
        cin >> t >> x;
        --x;
        ql[i] = {t, x};
        if(t == 1) {
            if(state[x]) events.push_back({prev[x], i, x});
            else prev[x] = i+1;
            state[x] = 1-state[x];
        }
    }

    for(int i = 0; i < n-1; i++) {
        if(state[i]) events.push_back({prev[i], m, i});
        state[i] = 0;
    }

    vector<int> par(n, -1);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        par[u] = p;
        for(int v: adj[u]) if(v != p) dfs(v, u, dfs);
    };
    dfs(0, -1, dfs);

    Node st(0, m+1);
    DSU dsu(n, par, adj);
    for(auto &[l, r, i]: events) {
        st.update(l, r+1, i);
    }
    st.walk(dsu);
}
