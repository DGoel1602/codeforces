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
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    if(n % 2 == 0) {
        ll mg = 0;
        for(int i = 0; i<n; i++) mg += (i % 2 == 0 ? (ll)-a[i] : (ll)a[i]);
        if(mg < 0LL) return void(cout << "NO\n");
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 1 5 5 4 3
// 1 5 5 7 6
// 0 4 4 6

// 2 1 3

// 1 1 3 2
// 1 2 3 2
// 0 1 3 2
// 0 0 2 2

// 3 2 1
// 1 0 1
// 1 2 3
