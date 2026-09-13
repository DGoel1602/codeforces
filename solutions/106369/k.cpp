#include <bits/stdc++.h>
#include <cassert>
using namespace std;

#define ssize(x) (int)(x).size()

auto cuts(const auto& adj, int m) {
    int n = ssize(adj), num_bccs = 0, q = 0, s = 0;
    vector<int> bcc_id(m, -1), is_cut(n), tin(n), st(m);
    auto dfs = [&](auto && self, int v, int p) -> int {
        int low = tin[v] = ++q;
        for(auto [u, e]: adj[v]) {
            assert(v != u);
            if(e == p) continue;
            if(tin[u] < tin[v]) st[s++] = e;
            int lu = -1;
            low = min(low, tin[u] ?: (lu = self(self, u, e)));
            if(lu >= tin[v]) {
                is_cut[v] = p >= 0 || tin[v] + 1 < tin[u];
                while(bcc_id[e] < 0) bcc_id[st[--s]] = num_bccs;
                num_bccs++;
            }
        }
        return low;
    };
    for(int i = 0; i<n; i++) if(!tin[i]) dfs(dfs, i, -1);
    return tuple{num_bccs, bcc_id, is_cut};
}

auto block_vertex_tree(const auto& adj, int num_bccs, const vector<int>& bcc_id) {
    int n = ssize(adj);
    vector<basic_string<int>> bvt(n + num_bccs);
    vector<bool> vis(num_bccs);
    for(int i = 0; i<n; i++) {
        for(auto [_, e_id]: adj[i]) {
            int bccid = bcc_id[e_id];
            if(!vis[bccid]) {
                vis[bccid] = 1;
                bvt[i] += bccid + n;
                bvt[bccid+n] += i;
            }
        }
        for(int bccid: bvt[i]) vis[bccid - n] = 0;
    }
    return bvt;
}

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V): jmp(1, V) {
        for(int pw = 1, k = 1; pw * 2 <= ssize(V); pw *= 2, ++k) {
            jmp.emplace_back(ssize(V) - pw * 2 + 1);
            for(int j = 0; j<ssize(jmp[k]); j++)
                jmp[k][j] = min(jmp[k-1][j], jmp[k-1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA {
    int T = 0;
    vector<int> time, path, ret;
    RMQ<int> rmq;

    LCA(vector<vector<int>>& C) : time(ssize(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vector<int>> &C, int v, int par) {
        time[v] = T++;
        for(int y: C[v]) if(y != par) {
            path.push_back(v), ret.push_back(time[v]);
            dfs(C, y, v);
        }
    }
    int lca(int a, int b) {
        if(a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i<m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    auto [num_bccs, bcc_id, is_cut] = cuts(adj, m);
    auto bvt = block_vertex_tree(adj, num_bccs, bcc_id);
    vector<vector<int>> adj2(n + num_bccs);
    for(int i = 0; i<n+num_bccs; i++) {
        for(int v: bvt[i]) adj2[i].push_back(v);
    }
    LCA lc(adj2);
    vector<int> vals(n+num_bccs), depths(n+num_bccs);
    auto dfs = [&](int u, int p, int cnt, int d, auto&& dfs) -> void {
        cnt += u < n && is_cut[u];
        vals[u] = cnt;
        for(int v: adj2[u]) if(v != p) dfs(v, u, cnt, d+1, dfs);
        depths[u] = d;
    };
    dfs(0, -1, 0, 0, dfs);
    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        --a; --b;
        if(depths[a] + depths[b] - 2 * depths[lc.lca(a, b)] == 2) {
            cout << "2\n";
            continue;        
        }
        cout << !is_cut[a] + !is_cut[b] + (lc.lca(a, b) < n && is_cut[lc.lca(a, b)]) + (vals[a] + vals[b] - 2 * vals[lc.lca(a, b)])  << '\n';
    }
}
