#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i< b; ++i)

void solve() {
    int n, m; cin >> n >> m;
    if(m >= 2 * n) return void(cout << "NO\n");
    cout << "YES\n";
    vector<vector<int>> colors(2 * n, vector(m, -1));
    int l = 0;
    for(int col = 0; col<n; col++) {
        for(int j = 0; j<m; j++) {
            int t = (l + j * 2) % (2 * n);
            int b = (l + j * 2 + 1) % (2 * n);
            if(j >= n) t = (t + 1) % (2 * n), b = (b + 1) % (2 * n);
            colors[t][j] = col;
            colors[b][j] = col;
        }
        l += 2;
    }
    for(auto vec: colors) {
        for(int c: vec) cout << c + 1 << " ";
        cout << "\n";
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
