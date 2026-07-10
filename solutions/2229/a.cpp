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
    sort(all(a));
    int med = (a[0] + a.back()) / 2;
    cout << max(med - a[0], a.back() - med) << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}


// 1 2 3 5 6 7
// 1 1 10 10 10
