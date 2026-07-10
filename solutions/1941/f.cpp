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
    int n, m, k; cin >> n >> m >> k;
    vi a(n), mo(m), f(k);
    for(int &x: a) cin >> x;
    for(int &x: mo) cin >> x;
    for(int &x: f) cin >> x;
    sort(all(f));

    if(n == 1) return void(cout << "0\n");

    vector<pii> gaps;
    rep(i, 1, n) gaps.push_back({a[i] - a[i-1], a[i-1]});
    sort(all(gaps), greater<>());

    int big = gaps[0].first;
    int st = gaps[0].second;
    int lo = (big+1)/2, hi = big;
    while(lo != hi) {
        int mid = lo + (hi - lo) / 2;
        int pl = st + mid, pl2 = st + big - mid;
        bool can = false;
        rep(i, 0, m) {
            pii lfr = {pl2 - mo[i], pl - mo[i]};
            if(upper_bound(all(f), lfr.second) - lower_bound(all(f), lfr.first) > 0) {
                can = true;
                break;
            }
        }
        if(can) hi = mid;
        else lo = mid + 1;
    }
    if(gaps.size() > 1) lo = max(lo, gaps[1].first);
    cout << lo << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
