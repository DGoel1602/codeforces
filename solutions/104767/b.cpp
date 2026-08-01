#include <bits/stdc++.h>
using namespace std;

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int n; cin >> n;
   vector<int> cnt(1 << 17, 0);
   for(int i = 0; i<n; i++) {
      string s; cin >> s;
      int o = 0;
      for(char c: s) o |= (1 << (c - 'a'));
      cnt[o]++;
   }
   vector<int> dp(cnt);
   for(int i = 0; i<17; i++) for(int mask = 0; mask < (1 << 17); mask++)
      if(!(mask & (1 << i))) dp[mask] += dp[mask ^ (1 << i)];

   vector<int> exc(dp);
   for(int i = 0; i<(1 << 17); i++) if(__builtin_popcount(i) % 2) exc[i] *= -1;
   exc[0] = 0;

   dp = vector<int>(exc);
   for(int i = 0; i<17; i++) for(int mask = 0; mask < (1 << 17); mask++)
      if(mask & (1 << i)) dp[mask] += dp[mask ^ (1 << i)];

   string s; cin >> s;
   int sz = n;
   n = s.size();
   vector<int> cur(17, -1); 
   long long ret = 0;
   for(int i = 0; i<n; i++) {
      cur[s[i] - 'a'] = i;
      vector<pair<int, int>> pos;
      for(int j = 0; j<17; j++) pos.push_back({cur[j], j});
      sort(pos.begin(), pos.end());
      int o = 0;
      for(auto [idx, j]: pos) {
         o |= (1 << j);
         if(abs(dp[o]) == sz) {
            ret += idx + 1;
            break;
         }
      }
   }
   cout << ret << '\n';
}
