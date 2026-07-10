#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<ll> a, b;
    ll suma = 0, sumb = 0;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        suma += x;
        a.insert(x);
    }
    for(int i = 0; i < m; i++) {
        ll x; cin >> x;
        sumb += x;
        b.insert(x);
    }

    if(suma != sumb) {
        cout << "No\n";
        return;
    }

    for(; !a.empty() && !b.empty(); ) {
        ll x = *b.begin();
        b.erase(b.begin());
        ll lo = x/2, hi = (x+1)/2;
        
        auto ix = a.find(x);
        if(ix != a.end()) {
            a.erase(ix);
            continue;
        }

        auto il = a.find(lo);
        if(il != a.end()) a.erase(il);
        else {
            if(lo == 1) break;
            b.insert(lo);
        }
        auto ih = a.find(hi);
        if(ih != a.end()) a.erase(ih);
        else {
            if(hi == 1) break;
            b.insert(hi);
        }
    }

    if(a.empty() && b.empty()) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
