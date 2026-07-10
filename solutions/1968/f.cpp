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
    int n,q; cin >> n >> q;
    vi a(n);
    for(int &x: a) cin >> x;
    vi sa(n+1, 0);
    for(int i = n-1; i>=0; i--) sa[i] = sa[i+1] ^ a[i];
    map<int, set<int>> idxs;
    rep(i, 0, n) idxs[sa[i]].insert(i);

    rep(i,0,q) {
        int l, r; cin >> l >> r;
        --l; --r;
        int rem = sa[r+1];
        if(l == r) {
            cout << "NO\n";
            continue;
        }
        if(sa[l] == rem) {
            cout << "YES\n";
            continue;
        }

        auto fz = idxs[rem].lower_bound(l);
        if(fz == idxs[rem].end()) {
            cout << "NO\n";
            continue;
        }
        auto ft = idxs[sa[l]].lower_bound((*fz)+1);
        if(ft == idxs[sa[l]].end() || *ft > r) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
