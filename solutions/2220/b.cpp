#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

void solve() {
    int n, m; cin >> n >> m;
    vi a(n);
    for(int &x: a) cin >> x;
    int cur = 1, mx = -1;
    for(int i = 1; i<n; i++) {
        if(a[i] == a[i-1]) cur++;
        else {
            mx = max(mx, cur);
            cur = 1;
        }
    }
    mx = max(mx, cur);
    if(mx >= m) return void(cout << "NO\n");
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
