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
    int n, k; cin >> n >> k;
    vi a(n);
    for(int &x: a) cin >> x;
    rep(i, 0, n) {
        bool works = true;
        rep(j, 0, n) {
            if(j == i) continue;
            if(abs(a[i]-a[j]) % k == 0) works = false;
        }
        if(works) return void(cout << "YES\n" << i + 1 << "\n");
    }
    cout << "NO\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
