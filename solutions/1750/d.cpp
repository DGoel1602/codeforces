#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

vi primes;
vi sieve(1e5, 1);
const ll mod = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); 
    for(int &x: a) cin >> x;
    int res = 1;
    rep(i, 1, n) {
        if(a[i-1] % a[i]) return void(cout << "0\n");
        int mul = a[i-1] / a[i];
        int num = mul;
        vi pf;
        for(int x: primes) {
            if(x * x > num) break;
            if(num % x == 0) pf.push_back(x);
            while(num % x == 0) num /= x;
        }
        if(num > 1) pf.push_back(num);
        int add = m / a[i];
        int diff = 0;
        for(int mask = 1; mask<(1 << sz(pf)); mask++) {
            int nm = 1;
            rep(j, 0, sz(pf)) if((mask >> j) & 1) nm *= pf[j];
            diff += (add / nm) * (__builtin_popcount(mask) % 2 == 1 ? -1 : 1);
        }
        add += diff;
        res = (res * add) % mod;
    }
    cout << res << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    rep(i,2,sz(sieve)) {
        if(!sieve[i]) continue;
        for(int j = i * i; j<sz(sieve); j += i) sieve[j] = 0;
        primes.push_back(i);
    }
    int t; cin >> t;
    while(t--) solve();
}
