#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<vector<int>> idxs(n+1);
    for(int i = 0; i<n; i++) idxs[a[i]].push_back(i);
    vector<pair<int, vector<int>>> sorted;
    for(int i = 1; i<=n; i++) sorted.push_back({i, idxs[i]});
    sort(sorted.begin(), sorted.end(), [&](pair<int, vector<int>> &a, pair<int, vector<int>> &b) -> bool { return a.second.size() > b.second.size(); });

    vector<int> res(n);
    int cur = 1 % sorted.size();
    for(int i = 0; i<sorted.size(); i++) {
        for(int _: idxs[sorted[i].first]) {
            while(sorted[cur].second.empty()) {
                cur = (cur + 1) % sorted.size();
            }
            res[sorted[cur].second.back()] = sorted[i].first;
            sorted[cur].second.pop_back();
        }
    }
    for(int x: res) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
