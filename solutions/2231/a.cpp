#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i< b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
   int n; cin >> n;
   rep(i, 0, n) cout << (2 * i) + 1 << " ";
   cout << "\n"; 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
