#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sz(x) (int)x.size()

auto sccs(const vector<vi>& adj) {
  int n = sz(adj), num_sccs = 0, q = 0, s = 0;
  vi scc_id(n, -1), tin(n), st(n);
  auto dfs = [&](auto&& self, int v) -> int {
    int low = tin[v] = ++q; st[s++] = v;
    for (int u : adj[v]) if (scc_id[u] < 0)
        low = min(low, tin[u] ?: self(self, u));
    if (tin[v] == low) {
      while (scc_id[v] < 0) scc_id[st[--s]] = num_sccs;
      num_sccs++; 
    } 
    return low;
  };
  rep(i,0,n) if (!tin[i]) dfs(dfs, i);
  return pair{num_sccs, scc_id};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vvi adj(n);
    rep(i, 0, m) {
        int u; cin >> u;
        --u;
        int s; cin >> s;
        rep(j, 0, s) {
            int v; cin >> v;
            --v;
            adj[u].push_back(v);
        }
    }
    auto [comps, id] = sccs(adj);
    vi deg(comps, 0);
    rep(u, 0, n) {
        for(int v: adj[u]) {
            if(id[u] == id[v]) continue;
            deg[id[v]]++;
        }
    }
    int res = 0, c = 0;
    rep(i, 0, comps) {
        if(deg[i] == 0) {
            if(c == 1) {
                cout << "0\n";
                return 0;
            }
            for(int ia: id) if(ia == i) res++;
            c++;
        }
    }
    if(c == 1) cout << res << "\n";
    else cout << "0\n";
}
