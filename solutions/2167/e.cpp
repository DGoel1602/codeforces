#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    sort(a.begin(), a.end());

    auto works = [&](int m) -> bool {
        if(m == 0) return true;
        vector<pair<int, int>> segs;
        for(int x: a) {
            pair<int, int> seg = {x-m+1, x+m-1};
            if(segs.size()) seg.first = max(seg.first, segs.back().second+1);
            segs.push_back(seg);
        }
        segs[0].first = max(segs[0].first, 0);
        segs.back().second = min(segs.back().second, x);
        int cnt = 0;
        for(auto [a, b]: segs) cnt += b - a + 1;
        return x + 1 - cnt >= k;
    };

    int lo = 0, hi = x;
    while(lo != hi) {
        int m = lo + (hi - lo + 1) / 2;
        if(!works(m)) hi = m - 1;
        else lo = m;
    }

    if(lo == 0) {
        for(int i = 0; i<k; i++) cout << i << " ";
        cout << "\n";
        return;
    }

    vector<pair<int, int>> segs;
    for (int x : a) {
        pair<int, int> seg = {x - lo + 1, x + lo - 1};
        if (segs.size())
            seg.first = max(seg.first, segs.back().second + 1);
        segs.push_back(seg);
    }
    segs[0].first = max(segs[0].first, 0);
    segs.back().second = min(segs.back().second, x);
    segs.push_back({x+1, x+2});

    int cur = 0;
    int placed = 0;
    for(auto [a, b]: segs) {
        for(; cur < a && placed < k; cur++) cout << cur << " ", placed++;
        cur = b + 1;
    }
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
