#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> ind(n);
    for(int i =0 ; i<n-1; i++) {
        int u, v, x, y; cin >> u >> v >> x >> y;
        --u; --v;
        if(y > x) adj[u].push_back(v), ind[v]++;
        else adj[v].push_back(u), ind[u]++;
    }
    queue<int> q;
    vector<int> res(n);
    for(int i = 0; i<n; i++) if(!ind[i]) q.push(i);
    int cur = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        res[u] = cur++;
        for(int v: adj[u]) {
            ind[v]--;
            if(!ind[v]) q.push(v);
        }
    }
    for(int x: res) cout << x << " ";
    cout << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
