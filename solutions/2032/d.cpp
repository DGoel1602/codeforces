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
    set<int> pp;
    vi par(n);
    rep(i,2,n) {
        cout << "? 1 " << i << endl;
        int r; cin >> r;
        pp.insert(i);
        par[i] = r ^ 1;
        if(r == 0) break;
    }
    int ls = *prev(pp.end());
    rep(i, ls + 1, n) {
        for(int x: pp) {
            cout << "? " << x << " " << i << endl;
            int r; cin >> r;
            if(r == 0) {
                par[i] = x;
                break;
            }
        }
        while(pp.size() && *pp.begin() <= par[i]) pp.erase(pp.begin());
        pp.insert(i);
    }
    cout << "! ";
    rep(i,1,n) cout << par[i] << " ";
    cout << "\n";
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
