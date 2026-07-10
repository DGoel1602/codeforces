#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
 
struct DSU {
    int n, cs;
    vi p, siz;
    DSU(int n): n(n), cs(n), siz(n), p(n) {
        iota(all(p), 0);
    }
 
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
 
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        if(siz[b] > siz[a]) swap(a, b);
        cs--;
        p[b] = a;
        siz[a] += siz[b];
        return true;
    }
};
 
void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    DSU f(n), g(n);
    vector<pii> edges;
    rep(i, 0, m1) {
        int u, v; cin >> u >> v;
        --u; --v;
        edges.push_back({u,v});
    }
    rep(i, 0, m2) {
        int u, v; cin >> u >> v;
        --u; --v;
        g.join(u, v);
    }
    int res = 0;
    for(auto [u, v]: edges) {
        if(g.find(u) == g.find(v)) f.join(u, v);
        else res++;
    }
    res += f.cs - g.cs;
    cout << res << "\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
