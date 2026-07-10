#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")

#define SIZ 200005

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for(int i = 1; i<n; i++) {
        int p; cin >> p;
        --p;
        adj[p].push_back(i);
    }

    vector<int> siz(n+1);
    int sl = 1e9;
    auto dfs = [&](int u, int d, auto&& dfs) -> void {
        siz[d]++;
        for(int v: adj[u]) dfs(v, d+1, dfs);
        if(!adj[u].size()) sl = min(sl, d);
    };
    dfs(0, 0, dfs);

    vector<int> pref(n+1, 0);
    pref[0] = siz[0];
    for(int i = 1; i<=sl; i++) pref[i] = pref[i-1] + siz[i];

    bitset<SIZ> bs, al;
    bs[k] = 1;
    for(int i = 0; i<=n; i++) al[i] = 1;
    int cur = n+1;

    int be = 0;
    for(int i = 0; i<=sl; i++) {
        int want = n-pref[i]+1;
        while(cur > want) {
            al[cur-1] = 0;
            cur--;
        }
        bs = (bs >> siz[i]) | (bs & al);
        if(bs.count()) be = i + 1;
    }
    cout << be << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
