#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve() {
    int n; cin >> n;
    int m, q; cin >> m >> q;
    vector<array<int, 4>> edges;
    vector<int> ps;
    for(int i = 0; i<m; i++) {
        int u, v, p, h; cin >> u >> v >> p >> h;
        ps.push_back(p);
        edges.push_back({p, h, --u, --v});
    }
    sort(edges.begin(), edges.end());

    vector<int> cp(ps);
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    // cout << cp.size() << endl;
    for(int i =0 ; i<m; i++) edges[i][0] = lower_bound(cp.begin(), cp.end(), edges[i][0]) - cp.begin(); 

    vector<vector<int>> fv(n, vector<int>(n, 1e17));
    for(int i = 0; i<n; i++) fv[i][i] = 0;

    vector<vector<int>> bests(cp.size(), vector<int>(n, 0));
    vector<int> tb(cp.size(), 1e17);
    for(int i = 0; i<m; i++) {
        auto [p, h, u, v] = edges[i];
        fv[u][v] = min(fv[u][v], h);
        for(int j = 0; j<n; j++) for(int k = 0; k<n; k++) {
            fv[j][k] = min(fv[j][k], fv[j][u] + fv[u][v] + fv[v][k]);
        }
        if(i == m-1 || edges[i+1][0] != edges[i][0]) {
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                    bests[p][i] = max(bests[p][i], fv[i][j]);
                }
            }
            for(int i = 0; i<n; i++) tb[p] = min(tb[p], bests[p][i]);
        }
    }

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int u, h; cin >> u >> h;
            --u;
            int lo = 0, hi = cp.size();
            while(lo != hi) {
                int m = lo + (hi - lo) / 2;
                if(bests[m][u] > h) lo = m + 1;
                else hi = m;
            }
            if(lo == cp.size()) {
                cout << "-1\n";
                continue;
            }
            cout << cp[lo] << '\n';
        } else {
            int h; cin >> h;
            int lo = 0, hi = cp.size();
            while(lo != hi) {
                int m = lo + (hi - lo) / 2;
                if(tb[m] > h) lo = m + 1;
                else hi = m;
            }
            if(lo == cp.size()) {
                cout << "-1 -1\n";
                continue;
            }
            int idx = n;
            for(int i = n-1; i>=0; i--) if(bests[lo][i] <= h) idx = i;
            cout << idx + 1 << " " << cp[lo] << '\n';
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

/*

5 6 4
1 2 1 3
2 3 1 1
3 4 1 2
4 5 1 3
5 1 1 2
1 3 2 1
1 1 9
2 8
1 1 8
1 1 5

2
0 3 4 6 9 
8 0 1 3 6 
7 10 0 2 5 
5 8 9 0 3 
2 5 6 8 0 

9 8 10 9 8 
0 3 1 3 6 
8 0 1 3 6 
7 10 0 2 5 
5 8 6 0 3 
2 5 3 5 0 

6 8 10 8 5 
1
1 1
1
1

*/
