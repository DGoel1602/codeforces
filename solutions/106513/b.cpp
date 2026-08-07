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
    double q; cin >> q;
    double lo = 0, hi = 3.14159265358979323846/2;
    rep(i, 0, 1000) {
        double m = (lo + hi) / 2;
        if(cos(m) < q * m) hi = m;
        else lo = m;
    }
    cout << fixed << setprecision(20) << lo << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while(t--) solve();
}
