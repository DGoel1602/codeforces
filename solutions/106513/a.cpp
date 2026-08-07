#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    vector<pii> as, bs;
    rep(i, 0, n) as.push_back({a[i], i});
    rep(i, 0, n) bs.push_back({b[i], i});
    sort(all(as));
    sort(all(bs));
    reverse(all(as));
    reverse(all(bs));
    if(as[0].second != bs[0].second) cout << as[0].first + bs[0].first << '\n';
    else {
        cout << max(as[0].first + bs[1].first, bs[0].first + as[1].first) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while(t--) solve();
}
