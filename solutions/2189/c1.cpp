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
    vector<int> res(n);
    res[0] = n-1;
    res[n-1] = 1;
    for(int i = 2; i<n; i++) {
        res[i-1] = i ^ 1;
    }
    if(n % 2 == 0) res[0] = n;
    for(int x: res) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
