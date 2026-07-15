#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define sz(a) (int)(a.size())
#define ll long long

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
  for(int i = 0; i < n; i++) if (!tin[i]) dfs(dfs, i);
  return pair{num_sccs, scc_id};
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<vector<int>> adj(n);

    stack<int> ms;
    for(int i = 0; i<n; i++) {
        while(ms.size() && a[ms.top()] <= a[i]) ms.pop();
        if(ms.size()) adj[i].push_back(ms.top());
        ms.push(i);
    }
    ms = stack<int>();

    vector<pair<int, int>> al;
    for(int i = 0; i<n; i++) al.push_back({a[i], i});
    sort(al.begin(), al.end());
    int ma = -1;
    for(auto [el, i]: al) {
        if(ma > i) adj[i].push_back(ma);
        ma = max(ma, i);
    }

    auto [c, scc_id] = sccs(adj);
    vector<ll> dp(c);
    vector<vi> dag(c);
    vector<int> indeg(c, 0);

    for(int i = 0; i < n; i++) {
        for(int v : adj[i]) {
            if(scc_id[i] != scc_id[v]) {
                dag[scc_id[v]].push_back(scc_id[i]);
                indeg[scc_id[i]]++;
            }
        }
    }

    vector<int> maxt(c, 0);
    for(int i = 0; i < n; i++) maxt[scc_id[i]] = max(maxt[scc_id[i]], a[i]);

    queue<int> q;
    for(int i = 0; i < c; i++) {
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : dag[u]) {
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
            maxt[v] = max(maxt[v], maxt[u]);
        }
    }

    for(int i = 0; i < n; i++) cout << maxt[scc_id[i]] << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
