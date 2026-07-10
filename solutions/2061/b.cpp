#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    sort(a.begin(), a.end());
    multiset<array<int, 3>> diff;
    for(int i = 0; i<n-1; i++) diff.insert({a[i+1] - a[i], a[i+1], a[i]});
    for(int i = 0; i<n-1; i++) {
        if(a[i+1] != a[i]) continue;

        diff.erase(diff.lower_bound({a[i+1]-a[i], a[i+1], a[i]}));
        if(i > 0) diff.erase(diff.lower_bound({a[i]-a[i-1], a[i], a[i-1]}));
        if(i < n-2) diff.erase(diff.lower_bound({a[i+2]-a[i+1], a[i+2], a[i+1]}));
        if(i > 0 && i < n-2) diff.insert({a[i+2] - a[i-1], a[i+2], a[i-1]});

        if(diff.size()) {
            auto bes = (*diff.begin());
            // cout << a[i] << " " << a[i+1] << " " << bes[0] << " " << bes[1] << " " << bes[2] << '\n';
            if(bes[0] / 2.0 < a[i]) {
                cout << a[i] << " " << a[i+1] << " " << bes[1] << " " << bes[2] << '\n';
                return;
            }
        }


        diff.insert({a[i+1]-a[i], a[i+1], a[i]});
        if(i > 0) diff.insert({a[i]-a[i-1], a[i], a[i-1]});
        if(i < n-2) diff.insert({a[i+2]-a[i+1], a[i+2], a[i+1]});
        if(i > 0 && i < n-2) diff.erase(diff.lower_bound({a[i+2] - a[i-1], a[i+2], a[i-1]}));
    }
    cout << -1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
