#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    int cur = 1;
    vvi grid(n, vi(n));
    rep(i, 0, n) {
        rep(j, 0, n) {
            grid[i][j] = cur;
            cur++;
        }
    }

    ll be = 0;
    rep(i, 0, n) {
        rep(j, 0, n) {
            ll res = 0;
            rep(dx, -1, 2) {
                rep(dy, -1, 2) {
                    if(dx != 0 && dy != 0) continue;
                    int ni = i + dy, nj = dx + j;
                    if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                    res += grid[ni][nj];
                }
            }
            be = max(res, be);
        }
    }
    cout << be << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
