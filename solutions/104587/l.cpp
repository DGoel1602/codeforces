#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<pair<int, int>>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)

struct MCMF {
    const ll INF = LLONG_MAX >> 2;
    struct edge {
        int v;
        ll cap, flow, cost;
    };
    int n;
    vector<edge> edges;
    vvi adj; vii par; vi in_q;
    vector<ll> dist, pi;
    MCMF(int n): n(n), adj(n), par(n), in_q(n), dist(n), pi(n) {}
    void addEdge(int u, int v, ll cap, ll cost) {
        int idx = sz(edges);
        edges.push_back({v, cap, 0, cost});
        edges.push_back({u, cap, cap, -cost});
        adj[u].push_back(idx);
        adj[v].push_back(idx ^ 1);
    }
    bool findPath(int s, int t) {
        fill(all(dist), INF);
        fill(all(in_q), 0);
        queue<int> q; q.push(s);
        dist[s] = 0, in_q[s] = 1;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            in_q[cur] = 0;
            for(int idx: adj[cur]) {
                auto [nxt, cap, fl, wt] = edges[idx];
                ll nxtD = dist[cur] + wt;
                if(fl >= cap || nxtD >= dist[nxt]) continue;
                dist[nxt] = nxtD;
                par[nxt] = {cur, idx};
                if(in_q[nxt]) continue;
                q.push(nxt); in_q[nxt] = 1;
            }
        }

        return dist[t] < INF;
    }
    pair<ll, ll> calc(int s, int t) {
        ll flow = 0, cost = 0;
        while(findPath(s, t)) {
            ll f = INF;
            for(int i, u, v = t; tie(u, i) = par[v], v != s; v = u)
                f = min(f, edges[i].cap - edges[i].flow);
            flow += f;
            for(int i, u, v = t; tie(u, i) = par[v], v != s; v = u)
                edges[i].flow += f, edges[i^1].flow -= f;
        }
        rep(i, 0, sz(edges)>>1)
            cost += edges[i<<1].cost * edges[i<<1].flow;
        return {flow, cost};
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vvi apt_to_gts(n, vi(2*n, 0));
    for(auto &vec: apt_to_gts) for(auto &x: vec) cin >> x;
    vvi gts_to_stns(n, vi(2*n, 0));
    for(auto &vec: gts_to_stns) for(auto &x: vec) cin >> x;

    int best = 1e9;
    vector<string> con;
    for(int a_cnt = 0; a_cnt <= n; a_cnt++) {
        MCMF dc(4 * n + 2);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                dc.addEdge(i, n+j, 1, apt_to_gts[i][2*j+(j>=a_cnt)]);
            }
        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                dc.addEdge(n+n+i, n+n+n+j, 1, gts_to_stns[j][2*i+(i>=a_cnt)]);
            }
        }
        for(int i = 0; i<n; i++) dc.addEdge(n+i, n+n+i, 1, 0);
        for(int i = 0; i<n; i++) {
            dc.addEdge(4*n, i, 1, 0);
            dc.addEdge(3*n+i, 4*n+1, 1, 0);
        }
        auto [f, c] = dc.calc(4*n, 4*n+1);
        assert(f == n);
        if(c < best) {
            best = c;
            con.clear();
            for(int i = 0; i<n; i++) {
                string res = "";
                res += to_string(i +1) + " ";
                int gt = -1;
                for(int j = 0; j<n; j++) {
                    if(dc.edges[(i*n+j)*2].flow > 0) {
                        res += to_string(j + 1) + (j>=a_cnt ? "B " : "A ");
                        gt = j;
                        break;
                    }
                }
                assert(gt != -1);
                for(int j = 0; j<n; j++) {
                    if(dc.edges[n*n*2+(gt*n+j)*2].flow > 0) {
                        res += to_string(j + 1);
                        break;
                    }
                }
                con.push_back(res);
            }
        }
    }
    cout << best << '\n';
    for(string x: con) cout << x << '\n';
    
}
