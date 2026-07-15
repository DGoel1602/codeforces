#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = 0; i < a; i++)

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vi cor1(n), cor2(n);
    for(int i = 0; i<n; i++) {
        if(s[i] - '0' != i % 2) cor1[i] = true;
        if(s[i] - '0' == i % 2) cor2[i] = true;
    }
    vi changes1(n), changes2(n);
    for(int i = 0; i<n; i++) {
        if(cor1[i] && (i == 0 || !cor1[i-1])) changes1[i] = 1;
        if(cor2[i] && (i == 0 || !cor2[i-1])) changes2[i] = 1;
    }
    vi pref1(n+1), pref2(n+1);
    for(int i = 1; i<=n; i++) pref1[i] = pref1[i-1] + changes1[i-1];
    for(int i = 1; i<=n; i++) pref2[i] = pref2[i-1] + changes2[i-1];

    while(q--) {
        int l, r, k; cin >> l >> r >> k;
        int a_cost = pref1[r] - pref1[l-1] + (cor1[l-1] && !changes1[l-1]);
        int b_cost = pref2[r] - pref2[l-1] + (cor2[l-1] && !changes2[l-1]);
        if(min(a_cost, b_cost) <= k) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
