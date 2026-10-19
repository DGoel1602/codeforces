#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)(a.size())

ll best = 0;

array<ll, 8> dfs(int u, int p, vector<vector<pair<int, ll>>>& tree, 
    vector<array<ll, 3>>& pts, ll dist) {
    array<ll, 8> ans;
    ans.fill(dist);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            if (i & (1 << j)) ans[i] += pts[u][j];
            else ans[i] -= pts[u][j];
        }
    }

    for (auto [v, w] : tree[u]) {
        if (v == p) continue;
        auto v_ans = dfs(v, u, tree, pts, dist+w);
        for (int i = 0; i < 8; i++) {
            best = max(best, ans[i] + v_ans[7^i] - 2*dist);
        }
        for (int i = 0; i < 8; i++) {
            ans[i] = max(ans[i], v_ans[i]);
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<array<ll, 3>> pts(n);
    vector<vector<pair<int, ll>>> tree(n);

    for (int i = 0; i < n-1; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        u--; v--;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    for (auto& [x, y, z] : pts) cin >> x >> y >> z;

    dfs(0, 0, tree, pts, 0);
    cout << best << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; //cin >> t;
    while(t--) solve();
}
