#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    for(int i = 0; i<n; i++) if(a[i] < b[i]) swap(a[i], b[i]);
    cout << accumulate(a.begin(), a.end(), 0LL) + *max_element(b.begin(), b.end()) << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
