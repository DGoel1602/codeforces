#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define sz(x) (int)((x).size())
#define all(x) begin(x), end(x)
using vi = vector<int>;

vi sieve(1000001);
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;

    map<int, vector<int>> ps;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        while (v != 1) {
            int c = sieve[v];
            int p = 0;
            while (!(v % c)) {
                v /= c;
                p++;
            }
            ps[c].push_back(p);
        }
    }

    vector<ll> guys(n, 1);

    for (auto& [i, v] : ps) {
        sort(all(v));
        reverse(all(v));
        for (int j = 0; j < sz(v); j++) {
            while (v[j]--) guys[j] = (guys[j] * (ll)i) % mod;
        }
    }

    cout << accumulate(all(guys), 0LL) % mod << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    iota(all(sieve), 0);
    for (int i = 2; i * i < sz(sieve); i++) {
        if (sieve[i] != i) continue;
        for (int j = i*i; j < sz(sieve); j += i) {
            sieve[j] = i;
        }
    }
    int t=1; cin >> t;
    while(t--) {
        solve();
    }
}
