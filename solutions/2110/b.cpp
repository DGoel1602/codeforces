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
    string s; cin >> s;
    int n = sz(s);
    int cur = 0;
    rep(i, 0, n-1) {
        cur += s[i] == ')' ? -1 : 1;
        if(cur == 0) return void(cout << "YES\n");
    }
    cout << "NO\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
