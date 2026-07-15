#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int ls = 0;
    for(int i = 0; i<n-1; i++) {
        if(ls+1 < a[i] && a[i] > 1) {
            a[i+1] += a[i] - (ls+1);
            a[i] = ls + 1;
        }
        ls = a[i];
    }
    for(int i = 1; i<n; i++) if(a[i-1] >= a[i]) return void(cout << "NO\n");
    cout << "YES\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
