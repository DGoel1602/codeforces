#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll m = 998244353;
ll modpow(ll b, ll e) {
    ll res = 1;
    for(; e; b = (b * b) % m, e >>= 1) {
        if(e & 1) res = (res * b) % m;
    }
    return res;
}

int main() {
    ll n; cin >> n;
    if(n <= 3) {
        cout << 1 << '\n';
        return 0;
    }
    n -= 2;
    int tw = n % 3;
    if(tw) tw = 3-tw;
    int thr = (n - 2*tw) / 3;

    ll res = modpow(3, thr);
    res = (res * modpow(2, tw)) % m;
    cout << res << '\n';
}
