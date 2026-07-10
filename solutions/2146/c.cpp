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
    string s; cin >> s;
    vi res(n);
    int cur = 0;
    for(char c: s) {
        if(c == '0') cur++;
        else {
            if(cur == 1) return void(cout << "NO\n");
            cur = 0;
        }
    }
    if(cur == 1) return void(cout << "NO\n");

    cout << "YES\n";
    rep(i, 0, n) if(s[i] == '1') res[i] = i;
    int ls = -1;
    rep(i, 0, n) {
        if(s[i] == '0') {
            if(i == 0 || s[i-1] == '1') ls = i;
            if(i < n-1 && s[i+1] == '0') res[i] = i+1;
            else res[i] = ls;
        }
    }
    for(int x: res) cout << x + 1 << " ";
    cout << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
