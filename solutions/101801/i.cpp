#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> podd(n+1), peven(n+1);
    podd[0] = peven[0] = 0;
    for(int i = 1; i <= n; i++) {
        podd[i] = podd[i-1] + (a[i] % 2 == 1);
        peven[i] = peven[i-1] + (a[i] % 2 == 0);
    }

    const ll mod = 1e9 + 7;
    vector<ll> p2(n+1);
    p2[0] = 1;
    for(int i = 1; i <= n; i++) {
        p2[i] = (2*p2[i-1]) % mod;
    }

    while(q--) {
        int l, r, t;
        cin >> l >> r >> t;
        int odd = podd[r] - podd[l-1], even = peven[r] - peven[l-1];
        if(t == 0) cout << (((p2[even]+mod-1) % mod) * p2[odd]) % mod << endl;
        else cout << (p2[odd]+mod-1) % mod << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
