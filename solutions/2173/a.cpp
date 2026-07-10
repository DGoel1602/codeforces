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
    string s; cin >> s;
    vector<int> up(n, 0);
    rep(i, 0, n) if(s[i] == '1') {
        for(int j = i; j<n && j <= i+k; j++) up[j] = 1;
    }
    cout << n - accumulate(all(up), 0) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
