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
    for(int &x: a) cin >> x;
    int mi = *min_element(all(a)) % 2, ma = *max_element(all(a)) % 2;
    if(ma == mi) return void(cout << "0\n");
    sort(all(a));
    int be = 1e9;
    for(int i = 0; i<n; i++) {
        if(a[i] % 2 != mi) be = min(be, i);
        if(a[i] % 2 != ma) be = min(be, n - i - 1);
    }
    cout << be << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
