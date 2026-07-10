#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    for(int &x: a) cin >> x;
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    n = a.size();

    map<int, int> idx;
    rep(i, 0, n) idx[a[i]] = i;
    vi accnt(n, 0);
    vi ret;
    rep(i, 0, n) {
        if(accnt[i]) continue;
        ret.push_back(a[i]);
        for(int j = a[i]; j<=k; j += a[i]) {
            auto it = idx.find(j);
            if(it == idx.end()) return void(cout << "-1\n");
            accnt[it->second] = 1;
        }
    }
    cout << ret.size() << '\n';
    for(int x: ret) cout << x << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
