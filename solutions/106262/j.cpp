#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++, deg[b]++;
    }

    for(int i = 0; i < n; i++) {
        if(adj[i].empty()) continue;
        sort(adj[i].begin(), adj[i].end());
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        if(deg[i] >= 4 || deg[i] <= 1) {
            if(deg[i] >= 4) res++;
            continue;
        }

        bool good = false;
        for(int x : adj[i]) {
            for(int y : adj[i]) {
                if(x == y) continue;
                int tar = 4-deg[i];

                int cur = 0;
                for(int k : adj[x]) {
                    if(k == i) continue;
                    if(find(adj[i].begin(), adj[i].end(), k) == adj[i].end()) cur++;
                    if(cur == tar) break;
                }
                if(cur < tar) continue;

                cur = 0;
                for(int k : adj[y]) {
                    if(k == i) continue;
                    if(find(adj[i].begin(), adj[i].end(), k) == adj[i].end()) cur++;
                    if(cur == tar) break;
                }
                if(cur < tar) continue;

                good = true;
            }
        }
        if(good) res++;
    }
    cout << res << '\n';
}
