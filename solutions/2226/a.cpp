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
    int n; cin >> n;
    vector<int> nums(n), vis(n, 0);
    for(int &x: nums) cin >> x;
    int s = 0, c = 0;
    while(c != n) {
        int st = 1, ls = 0;
        for(int i = 0; i<n; i++) {
            int x = nums[i];
            if(vis[i]) continue;
            if(x >= ls) {
                vis[i] = 1;
                st *= x;
                ls = x;
                c++;
                if(x != 1) break;
            }
        }
        s += st;
    }
    cout << s << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
