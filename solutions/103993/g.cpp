#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    multiset<ll> s;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        s.insert(x);
    }
    for(; n > 1; n--) {
        ll lo = *s.begin();
        s.erase(s.begin());
        ll hi = *prev(s.end());
        s.erase(prev(s.end()));
        s.insert((lo+hi)/2);
    }
    cout << *s.begin() << '\n';
}
