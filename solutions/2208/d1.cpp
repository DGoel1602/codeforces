#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) x.begin(), x.end()

struct DSU {
    int n;
    vi p, sz;
    DSU(int n): n(n), sz(n, 1), p(n) {
        iota(all(p), 0);
    }

    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    bool join(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        p[b] = a;
        return true;
    }
};

void solve() {
    int n; cin >> n;
    vector<string> adj(n);
    rep(i, 0, n) cin >> adj[i];

    rep(i, 0, n) {
        if(adj[i][i] == '0') return void(cout << "NO\n");
        adj[i][i] = '0';
    }

    vector<pii> edges;
    rep(i, 0, n) {
        vi freqs(n);
        rep(j, 0, n) {
            if(adj[i][j] == '0') continue;
            rep(k, 0, n) {
                if(adj[j][k] == '0') continue;
                freqs[k]++;
            }
        }

        rep(j, 0, n) {
            if(adj[i][j] == '0' && freqs[j]) return void(cout << "NO\n");
            if(adj[i][j] == '0') continue;
            if(freqs[j] == 0) edges.push_back({i, j});
        }
    }

    if(edges.size() != n - 1) return void(cout << "NO\n");

    DSU dsu(n);
    for(auto [u, v]: edges) if(!dsu.join(u, v)) return void(cout << "NO\n");

    cout << "YES\n";
    for(auto [u, v]: edges) cout << u + 1 << " " << v + 1 << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();
}
