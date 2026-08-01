#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Gear {
    int x, y, r;
    Gear(int x, int y, int r): x(x), y(y), r(r) {}
};

using pii = pair<int, int>;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<Gear> gs(n, Gear(0, 0, 0));
    for(int i = 0; i<n; i++) {
        int x, y, r; cin >> x >> y >> r;
        gs[i] = Gear(x, y, r);
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(i == j) continue;
            int dx = gs[j].x - gs[i].x;
            int dy = gs[j].y - gs[i].y;
            if(dx * dx + dy * dy == (gs[j].r + gs[i].r) * (gs[j].r + gs[i].r)) {
                adj[i].push_back(j);
            }
        }
    }

    vector<pii> res(n, {-10000, -10000});
    vector<int> seen(n);
    res[0] = {1, 1};
    queue<int> q;
    q.push(0);
    seen[0] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: adj[u]) {
            pii to = {-res[u].first * gs[u].r, res[u].second * gs[v].r};
            int g = __gcd(abs(to.first), to.second);
            to.first /= g;
            to.second /= g;
            if(!seen[v]) {
                res[v] = to;
                seen[v] = 1;
                q.push(v);
            } else if(res[v] != to) {
                cout << "The input gear cannot move.\n";
                return 0;
            }
        }
    }

    if(!seen[n-1]) {
        cout << "The input gear is not connected to the output gear.\n";
        return 0;
    }
    pii fin = res[n-1];
    cout << fin.first << ":" << fin.second << '\n';
}
