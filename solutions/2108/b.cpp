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
    int n, x; cin >> n >> x;
    if(x == 0 && n == 1) return void(cout << "-1\n");
    int s = x;
    int left = n - min(n, __builtin_popcount(x));
    s += left - (left % 2);
    //cout << bitset<32>(x) << " " << left << " " << s << "\n";
    if(left % 2 == 1) {
        if(x < 2) s += 4;
        else s += 2;
    };
    cout << s << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
