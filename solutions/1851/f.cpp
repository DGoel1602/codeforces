#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<pair<int, int>> ps;
    for(int i = 0; i<n; i++) ps.push_back({a[i], i});
    sort(ps.begin(), ps.end());
    array<int, 3> best;
    int high = -1;
    for(int i = 0; i<n-1; i++) {
        int a = ps[i].first, b = ps[i+1].first;
        int x = (a ^ (~(a^b))) & ((1 << k) - 1);
        if(((x^a)&(x^b)) > high) {
            high = (x^a)&(x^b);
            best = {ps[i].second, ps[i+1].second, x};
        }
    }
    cout << best[0] + 1 << " " << best[1] + 1 << " " << best[2] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
