#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) cin >> grid[i][j];

    vector<vector<int>> pref(n+1, vector<int>(m+1, 0));
    for(int i = 1; i<=n; i++) for(int j = 1; j<=m; j++) {
        pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + grid[i-1][j-1];
    }

    auto sum = [&](int i, int j, int end, int m) -> int {
        return pref[end+1][m+1] - pref[end+1][j] - pref[i][m+1] + pref[i][j];
    };

    int best = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            for(int end = i; end < n; end++) {
                if(sum(i, j, end, j) > k) break;

                int lo = j, hi = m-1;
                while(lo != hi) {
                    int mid = lo + (hi - lo + 1) / 2;
                    int total = sum(i, j, end, mid);
                    if(total > k) hi = mid - 1;
                    else lo = mid;
                }
                best = max(best, (lo - j + 1) * (end - i + 1));
            }
        }
    }

    cout << best << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();
}
