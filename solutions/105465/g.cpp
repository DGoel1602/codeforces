#include <bits/stdc++.h>
using namespace std;
#include <assert.h>

using ll = long long;
#define sz(a) (int)(a).size()
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(int i = (a); i < (b); i++)

vector<pair<ll, ll>> vals;
vector<int> dist;

const ll inf = 1e18;

ll DP[2][300000];

ll dp(int f, int u, vector<vector<int>>& g) {
    if (DP[f][u] != -inf) return DP[f][u];
    ll ans = -inf+1;
    if (dist[u]-f) ans = vals[u].first - (dist[u]-f) * vals[u].second;
    for (auto v : g[u]) {
        if (dist[v]<dist[u]) continue;
        if (dist[u]-f < dist[v])
            ans = max(ans, dp(f&(dist[u]<dist[v]), v, g));
    }

    return DP[f][u] = ans;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        vals.emplace_back(a, b);
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dist = vector<int>(n, -1);
    dist[0] = 0;
    vector<int> q;
    q.push_back(0);
    int p = 0;
    multiset<ll> s;
    vector<ll> plus1(n, -inf);
    plus1[0] = vals[0].first - vals[0].second;
    s.insert(plus1[0]);
    while (p < sz(q)) {
        int u = q[p++];
        for (auto v : graph[u]) {
            if (dist[v]==-1) {
                dist[v]=dist[u]+1;
                s.insert(plus1[v] = vals[v].first - (dist[v]+1)*vals[v].second);
                q.push_back(v);
            }
        }
    }

    sort(all(graph[0]));
    for (auto v : graph[0]) {
        s.erase(s.find(plus1[v]));
        cout << max(*rbegin(s), dp(1, v, graph)) << '\n';
        s.insert(plus1[v]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 300000; i++) {
        DP[0][i] = DP[1][i] = -inf;
    }

    int T=1;
    // cin >> T;
    while (T--) {
        solve();
    }
}
