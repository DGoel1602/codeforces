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
    vi freq(3);
    rep(i, 0, n) {
        int x; cin >> x; freq[x]++;
    }
    int res = freq[0] + min(freq[1], freq[2]);
    int m = min(freq[1], freq[2]);
    freq[1] -= m;
    freq[2] -= m;
    cout << res + (freq[1]/3) + (freq[2]/3) << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
