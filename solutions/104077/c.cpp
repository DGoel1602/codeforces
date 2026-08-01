#include <bits/stdc++.h>
using namespace std;
//#include <cassert>
#define ll long long

ll a, b, c;
ll ans(ll m) {
    ll p = (1 << __lg(m));
    if(__builtin_popcount(m) != 1) p <<= 1;
    ll k = __lg(p)*a;
    ll x = p-m;

    ll c1 = c-(a/b)*x, c2 = c-((a+b-1)/b)*x;
    if(c1 <= 0) return k;
    if(c2 <= 0) return (k-a) + ((a+b-1)/b)*b;

    ll r1 = b*((c-(a/b)*x+m-1)/m) + k;
    ll r2 = b*((c-((a+b-1)/b)*x+m-1)/m) + (k-a) + ((a+b-1)/b)*b;

    return min(r1, r2);
}

/*
ll test(ll a, ll b, ll c) {
    ll res = ans(c);
    for(ll i = 1; i < c; i++) res = min(res, ans(i));
    return res;
}
*/

void solve() {
    cin >> a >> b >> c;
    ll res = ans(c);
    for(ll i = 1; i <= c * 2; i*=2) {
        res = min(res, ans(i));
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
