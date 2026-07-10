#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    sort(all(a));
    if(a.size() >= 2 && a.back() >= 2 && a[a.size()-2] >= 2) return void(cout << "YES\n");
    if(a.back() >= 3) return void(cout << "YES\n");
    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
