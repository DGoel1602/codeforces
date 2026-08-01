#include <bits/stdc++.h>
using namespace std;

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int n; cin >> n;
   vector<int> freq(21);
   for(int i = 0; i<n; i++) {
      int x; cin >> x;
      freq[x]++;
   }
   vector<vector<int>> dp(1 << 20, vector(20, -1));

   auto go = [&](int m, int l, auto&& go) {
      if(m == (1 << 20) - 1) return 0;
      auto &ref = dp[m][l-1];
      if(ref != -1) return ref;
      ref = 0;
      for(int i = 1; i<=20; i++) if(!(m & (1 << (i-1)))) {
         if(!freq[i]) continue;
         int sc = __gcd(l, i) + (freq[i] - 1) * i;
         ref = max(ref, sc + go(m | (1 << (i-1)), i, go));
      }
      return ref;
   };

   int be = 0;
   for(int i = 1; i <= 20; i++) if(freq[i]) be = max(be, (freq[i] - 1) * i + go(1 << (i-1), i, go));
   cout << be << '\n';
}
