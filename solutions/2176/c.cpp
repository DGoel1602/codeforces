#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()


void solve() {
    int n; cin >> n;
    vi a(n);
    for(ll &x: a) cin >> x;

    vi odds, evens;
    for(int x: a) (x % 2 == 1 ? odds : evens).push_back(x);
    sort(all(odds));
    sort(all(evens));
    reverse(all(evens));

    if(odds.empty()) {
        for(int i = 0; i<n; i++) cout << "0 ";
        cout << "\n";
        return;
    }
    if(evens.empty()) {
        for(int i = 0; i<n; i++) cout << ((i % 2 == 0) ? odds.back() : 0) << " ";
        cout << "\n";
        return;
    }

    vi res(n);
    ll s = odds.back();
    res[0] = s;
    for(int i = 0; i<evens.size(); i++) {
        s += evens[i];
        res[i+1] = s;
    }
    for(int i = evens.size() + 1; i<n; i++) {
        res[i] = res[i-2];
    }
    if(odds.size() % 2 == 0) res[res.size()-1] = 0;

    for(int x: res) cout << x << " ";
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
