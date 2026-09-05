#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define sz(a) (int)(a.size())

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V): jmp(1, V) {
        for(int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            for(int j = 0; j<sz(jmp[k]); j++)
                jmp[k][j] = min(jmp[k-1][j], jmp[k-1][j+pw]);
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
    LCA(vector<vector<int>> &C, int r): time(sz(C)), rmq((dfs(C,r,-1), ret)) {}
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

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    --a, --b;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<int> subb;
    vector<int> ss(n, 1), depth(n), par(n);
    auto dfs = [&](int u, int p, int d, bool sb, auto &&dfs) -> int {
        for(int v : adj[u]) {
            if(v == p) continue;
            ss[u] += dfs(v, u, d+1, sb || (u == b), dfs);
        }
        if(sb) subb.insert(u);
        par[u] = p;
        depth[u] = d;
        return ss[u];
    };
    dfs(a, -1, 0, false, dfs);
    subb.insert(b);

    vector<int> path;
    int cur = b;
    while(cur != a) {
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());

    LCA lc(adj, a);

    ll res = 0;
    for(int i = 0; i < n; i++) {
        if(subb.find(i) != subb.end()) continue;
        int v = lc.lca(i, b);
        int nxt = path[depth[v]+1];
        res += ss[nxt];

    }
    cout << res << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
