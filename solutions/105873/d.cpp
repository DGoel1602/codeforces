#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int k; cin >> k;
    vector<int> a(k);
    for(int &x: a) cin >> x;

    int n; cin >> n;
    vector<vector<int>> grid(n, vector(k, 0LL));

    for(auto &vec: grid) for(int &x: vec) cin >> x;

    pair<int, int> best = {(int)1e18, (int)1e18};
    for(int ing = 0; ing<k; ing++) {
        vector<int> al;
        for(int i = 0; i<n; i++) al.push_back(grid[i][ing]);
        vector<int> pref(n+1);
        for(int i = 1; i<n+1; i++) pref[i] = pref[i-1] + al[i-1];

        int tot = a[ing];
        int days = tot / pref[n];
        if(pref[n] == 0) continue;
        int idx = upper_bound(pref.begin(), pref.end(), tot % pref[n]) - pref.begin();
        best = min(best, {days+1, idx});
    }
    cout << best.first << " " << best.second << "\n";
}
