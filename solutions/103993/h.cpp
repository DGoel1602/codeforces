#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ls(n), rs(n);
    for(int i = 0; i < n; i++) {
        cin >> ls[i].first >> ls[i].second;
        rs[i] = ls[i];
    }
    sort(ls.begin(), ls.end());
    sort(rs.begin(), rs.end(), [&](pair<int, int> a, pair<int, int> b) {
        return tie(a.second, a.first) > tie(b.second, b.first);
    });

    int bp = 1;
    for(int i = 0; i < n; i++) {
        if(ls[i].first <= bp) bp = max(bp, ls[i].second+1);
        else break;
    }
    int ep = m;
    for(int i = 0; i < n; i++) {
        if(rs[i].second >= ep) ep = min(ep, rs[i].first-1);
        else break;
    }
    cout << max(ep-bp+1, 0) << '\n';
}
