#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    if(n == 1) return void(cout << "1\n");

    int be = LLONG_MAX;
    for(int skip = 0; skip<n; skip++) {
        vector<int> a2;
        for(int i = 0; i<n; i++) {
            if(i != skip || n % 2 == 0) a2.push_back(a[i]);
        }

        vector<int> diffs;
        for(int i = 0; i<a2.size()-1; i+=2) diffs.push_back(a2[i+1] - a2[i]);
        sort(diffs.begin(), diffs.end());
        be = min(be, diffs.size() ? diffs.back() : 1);
    }
    cout << be << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
