#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i< b; ++i)

void solve() {
    int n; cin >> n;
    cout << (n % 33 == 0 ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
