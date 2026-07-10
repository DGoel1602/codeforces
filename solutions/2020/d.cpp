#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

struct DSU {
    int n, comps;
    vi p, siz;
    DSU(int n): n(n), comps(n), p(n), siz(n, 1) {
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
        comps--;
        siz[a] += siz[b];
        p[b] = a;
        return true;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> bests(11, vector<pii>(11, {-1,-1}));
    vector<array<int, 3>> qs;
    rep(_, 0, m) {
        int a, d, k; cin >> a >> d >> k;
        qs.push_back({a, d, k});
    }
    sort(all(qs));
    
    DSU dsu(n+1);
    int cur = 0;
    rep(i, 1, n+1) {
        while(cur < m && qs[cur][0] < i) {
            auto [idx, d, k] = qs[cur];
            auto &ref = bests[d][idx%d];
            if(idx + d * k > ref.first) {
                if(ref.first >= idx) dsu.join(idx, ref.second);
                ref = {idx+d*k, idx};
            }
            cur++;
        }
        rep(j, 1, 11) {
            if(bests[j][i % j].first >= i) {
                dsu.join(i, bests[j][i%j].second);
            }
        }
    }
    cout << dsu.comps - 1 << "\n";
};
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
