#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    ll s = 0, t = 0;
    for(int i = n-1; i>=0; i--) {
        a[i] += s;
        if(a[i] >= 0) {
            s = a[i];
            if(a[i] > 0) t++;
        }
        else s = 0;
    }
    cout << t << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
