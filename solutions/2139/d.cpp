#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    stack<int> ms;
    vector<int> right(n, n), left(n, -1);
    for(int i = n-1; i>=0; i--) {
        while(ms.size() && a[ms.top()] > a[i]) ms.pop();
        if(ms.size()) right[i] = ms.top();
        ms.push(i);
    }

    ms = stack<int>();
    for(int i = 0; i<n; i++) {
        while(ms.size() && a[ms.top()] < a[i]) ms.pop();
        if(ms.size()) left[i] = ms.top();
        ms.push(i);
    }

    set<pair<int, int>> ranges;
    for(int i = 0; i<n; i++) ranges.insert({right[i], left[i]});
    vector<array<int, 3>> qs;
    for(int i = 0; i<q; i++) {
        int l, r; cin >> l >> r;
        --l; --r;
        qs.push_back({r, l, i});
    }
    sort(qs.begin(), qs.end());
    vector<int> res(q);
    set<pair<int, int>> exist;
    for(auto [en, st, i]: qs) {
        while(ranges.size() && (*ranges.begin()).first <= en) {
            auto [e, s] = *ranges.begin();
            ranges.erase(ranges.begin());
            exist.insert({s, e});
        }
        res[i] = (exist.lower_bound({st, 0}) != exist.end());
    }
    for(int x: res) cout << (x ? "NO\n" : "YES\n");
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
