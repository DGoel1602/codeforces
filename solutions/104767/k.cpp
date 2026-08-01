#include <bits/stdc++.h>
using namespace std;
#define forr(i,n) for(int i=0;i<n;++i)
#define ends(v) v.begin(),v.end()

#define int long long

const int mod = 1e9 + 7;

signed main() {
   cin.tie(0)->sync_with_stdio(0);
   int d, r; cin >> d >> r;
   vector<vector<pair<int, int>>> dp(d, vector<pair<int, int>>(r*r+1, {-1, -1}));
   auto go = [&](int dim, int left, auto&& go) -> pair<int, int> {
      if(dim == d) return {0, 1};
      auto &ref = dp[dim][left];
      if(ref.first != -1) return ref;
      ref = {0, 0};
      for(int i = 1; i * i <= left; i++) {
         auto res = go(dim+1, left - i * i, go);
         ref = {(ref.first + 2 * (i * res.second + res.first) % mod) % mod, (2 * res.second + ref.second) % mod};
      }
      auto res = go(dim+1, left, go);
      ref = {(ref.first + res.first) % mod, (res.second + ref.second) % mod};
      return ref;
   };
   cout << go(0, r * r, go).first << '\n';
}
