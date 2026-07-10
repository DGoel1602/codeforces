#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n, k; cin >> n >> k;
    if(k == 1) return void(cout << n << "\n");
    int res = 0;
    while(n) {
        int cur = 1;
        if(k > n) {
            res += n;
            break;
        }
        while(cur * k <= n) cur *= k;
        n -= cur;
        res++;
    }
    cout << res << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
