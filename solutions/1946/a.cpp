#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    sort(all(a));
    cout << (upper_bound(all(a), a[(n-1)/2]) - a.begin()) - ((n-1)/2) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
