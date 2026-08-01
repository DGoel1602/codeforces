#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
   cin.tie(0)->sync_with_stdio(0);
   ll c; cin >> c;
   int m; cin >> m;
   vector<ll> a(m);
   for(ll& x: a) cin >> x;
   set<ll> s;
   for(ll x: a) {
      if(c % x == 0 && s.count(c / x)) cout << min(x, c/x) << " " << max(x, c / x) << '\n';
      s.insert(x);
   }
}
