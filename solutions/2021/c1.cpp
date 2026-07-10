#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vi a(n), b(m);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;

    vi rb;
    set<int> seen;
    for(int x: b) if(!seen.count(x)) rb.push_back(x), seen.insert(x);

    for(int i = 0; i<rb.size(); i++)
        if(a[i] != rb[i]) return void(cout << "TIDAK\n");
    cout << "YA\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
