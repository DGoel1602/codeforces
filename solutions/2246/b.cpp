#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

void solve() {
    int n; cin >> n;
    if(n == 2) return void(cout << "-1\n");
    if(n == 1) return void(cout << "1\n");
    cout << "1 2 ";
    int sum = 3;
    for(int i = 2; i<n; i++) {
        cout << sum << " ";
        sum += sum;
    }
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
