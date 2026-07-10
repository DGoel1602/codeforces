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
    vi a(n);
    for(int &x: a) cin >> x;
    vi sorted(a);
    sort(all(sorted), greater<>());

    int mi = 0;
    for(int i = 1; i<n; i++) if(a[i] > a[mi]) mi = i;
    set<pii> cv;
    cv.insert({a[mi], mi});
    set<pii> nr;
    for(int i = 0; i<n; i++) nr.insert({a[i], i});
    vector<int> visited(n, 0);

    int robs = 1, cur = 0;
    while(cur < n) {
        auto ne = cv.lower_bound({sorted[cur], 0});
        auto [x, i] = *ne;

        if(ne == cv.end() || x != sorted[cur]) {
            robs++;
            cv.insert(*nr.lower_bound({sorted[cur], 0}));
            continue;
        }

        nr.erase(*ne);
        cv.erase(ne);
        visited[i] = 1;

        if(i > 0 && !visited[i-1]) cv.insert({a[i-1], i-1});
        if(i < n-1 && !visited[i+1]) cv.insert({a[i+1], i+1});
        cur++;
    }
    cout << robs << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
