#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vi a(n); 
    for(int &x: a) cin >> x;
    
    int par = 0;
    vi res;
    for(int i = n-1; i>=0; i--) {
        int tp = a[i] > 0;
        if(tp ^ par) {
            res.push_back(i);
            par ^= 1;
        }
    }
    cout << res.size() << "\n";
    for(int x: res) cout << x + 1 << " ";
    cout << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
