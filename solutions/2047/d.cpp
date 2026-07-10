#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    vector<pair<int, int>> els;
    for(int i = 0; i<n; i++) els.push_back({a[i], i});
    sort(els.begin(), els.end());
    int cur = 0;
    multiset<int> fin;
    vi res;
    for(auto [el, i]: els) {
        if(i < cur) continue;
        if(fin.size() && el > *fin.begin()) {
            for(; cur<n; cur++) fin.insert(a[cur] + 1);
            break;
        }
        for(; cur<i; cur++) {
            fin.insert(a[cur] + 1);
        }
        res.push_back(a[i]);
        cur = i + 1;
    }
    for(int x: res) cout << x << " ";
    for(int x: fin) cout << x << " ";
    cout << "\n";
}

signed main() {
    //cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
