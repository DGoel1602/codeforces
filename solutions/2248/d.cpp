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
    int n, q; cin >> n >> q;
    string s, t; cin >> s >> t;
    vi d_pref(n+1, 0);
    for(int i = 0; i<n; i++) d_pref[i+1] = d_pref[i] + (s[i] != t[i] ? (s[i] == '0' ? 1 : -1) : 0);
    vi pref(n+1, 0);
    for(int i = 0; i<n; i++) pref[i+1] = pref[i] + (s[i] == t[i]);

    while(q--) {
        int l, r; cin >> l >> r;
        int diffs = abs(d_pref[r] - d_pref[l-1]);
        int mx = pref[r] - pref[l-1];
        cout << (mx >= diffs ? "YES\n" : "NO\n");
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
