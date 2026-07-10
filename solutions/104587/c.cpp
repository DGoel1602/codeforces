#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<string, int> mp;
    vector<pair<string, string>> vec;
    for(int i = 0; i<n; i++) {
        string _, a, b; cin >> _ >> a >> b;
        vec.push_back({a, b});
        mp[a] = i;
    }
    vector<int> adj(n, -1);
    for(int i = 0; i<n; i++) {
        auto [a, b] = vec[i];
        if(mp.count(b)) adj[i] = mp[b];
    }
    
    vector<int> seen(n, 0);
    int be = 0;
    for(int i = 0; i<n; i++) {
        int cur = i;
        int res = 0;
        while(cur != -1 && !seen[cur]) {
            seen[cur] = 1;
            cur = adj[cur];
            res++;
        }
        if(cur != i) continue;
        be = max(be, res);
    }
    cout << (be == 0 ? "No trades possible" : to_string(be)) << '\n';
}
