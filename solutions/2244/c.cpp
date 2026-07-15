#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

struct DSU {
    int n;
    vi p, siz;
    DSU(int n): n(n), p(n), siz(n, 1) {
        iota(all(p), 0);
    }

    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        if(siz[a] < siz[b]) swap(a, b);
        p[b] = a;
        siz[a] += siz[b];
        return true;
    }
};

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vi a(n);
    for(int &x: a) cin >> x;
    DSU dsu(n);
    for(int i = 0; i<n; i++) {
        if(i-x >= 0) dsu.join(i-x, i);
        if(i-y >= 0) dsu.join(i-y, i);
        if(i+x <  n) dsu.join(i+x, i);
        if(i+y <  n) dsu.join(i+y, i);
    }
    vi seen(n);
    for(int i = 0; i<n; i++) {
        if(seen[i]) continue;
        vi path;
        int cur = a[i]-1;
        path.push_back(i);
        seen[i] = true;
        while(cur != i) {
            path.push_back(cur);
            seen[cur] = true;
            cur = a[cur]-1;
        }
        int g = dsu.find(i);
        for(int j = 1; j<path.size(); j++) 
            if(dsu.find(path[j]) != g) return void(cout << "NO\n");
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
