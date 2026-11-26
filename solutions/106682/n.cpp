#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;

using ll = long long;
ll modpow(ll b, ll e) {
    ll res = 1;
    for(; e; b=(b*b)%mod, e/=2)
        if(e & 1) res = (res * b) % mod;
    return res;
}


vector<int> fact(2e6, 1);

ll choose(ll n, ll k) {
    if(n < k) return 0;
    return (fact[n] * modpow((fact[k] * fact[n-k]) % mod, mod-2)) % mod;
}


ll n, k, c; 


signed main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int i = 2; i<2e6; i++)
        fact[i] = (fact[i-1] * i) % mod;
    
    cin >> n >> k >> c;

    if(n == 1) {
        if(k == 0) cout << c << '\n';
        else cout << "0\n";
        return 0;
    }
    if(n - 2 - k < 0) return(cout << "0\n", 0); 

    cout << ((((c * c) % mod * choose(n - 2, k)) % mod) * modpow(c - 1, n - 2 - k)) % mod << '\n';

}
