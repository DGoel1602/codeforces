#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)(a).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int res = 0;
    vector<bool> seen(n, false);
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(seen[i]) continue;
        int nc = 1, ec = sz(adj[i]);
        q.push(i); seen[i] = true;

        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : adj[u]) {
                if(seen[v]) continue;
                seen[v] = true;
                nc++, ec += sz(adj[v]);
                q.push(v);
            }
        }

        ec /= 2;
        res += ec-nc+1;
    }
    cout << res << '\n';
}
