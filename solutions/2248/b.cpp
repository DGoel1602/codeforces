#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m; cin >> n >> m;

    vi a(n), b(m);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    sort(all(b));
    sort(all(a));

    int p = 0;
    for(int i = 0; i<m; i++, p++)
        if(a[p] > b[i]) return void(cout << "NO\n");
    int p2 = n-1;
    for(int i = m-1; i>=0; i--, p2--)
        if(a[p2] < b[i]) return void(cout << "NO\n");
    if(p2 < p - 1) return void(cout << "NO\n");
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
