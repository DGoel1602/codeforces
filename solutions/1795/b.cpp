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
    int n, k; cin >> n >> k;     
    bool l = false, r = false;
    rep(i, 0, n) {
        int le, ri; cin >> le >> ri;
        if(le == k) l = true;
        if(ri == k) r = true;
    }
    cout << (l && r ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
