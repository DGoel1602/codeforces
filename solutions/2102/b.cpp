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
    for(int &x: a) cin >> x, x = abs(x);
    int tar = a[0];
    sort(all(a));
    int bef = 0;
    rep(i, 0, n) {
        if(a[i] == tar) {
            bef = i;
            break;
        }
    }
    int taridx = (n - 1) / 2;
    if(bef <= taridx || (n - bef - 1) >= taridx) cout << "YES\n";
    else cout << "NO\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 1 2 7 8
// 4 - 1 / 2 = 1
